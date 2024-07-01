import tkinter as tk
from tkinter import messagebox, filedialog
from tkinter import ttk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import os

# 假设 FAT32 类已定义在 fat32.py 文件中
from fat32 import FAT32

class FAT32Browser(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("FAT32 File System Browser")
        self.geometry("800x600")

        self.volumes = self.get_volumes()
        self.vol = None
        self.current_volume = None

        self.create_widgets()

    def create_widgets(self):
        self.volume_label = tk.Label(self, text="Available FAT32 volumes:")
        self.volume_label.pack()

        self.volume_listbox = tk.Listbox(self)
        for i, volume in enumerate(self.volumes):
            self.volume_listbox.insert(tk.END, f"{i + 1}.{volume}")
        self.volume_listbox.pack()
        self.volume_listbox.bind("<Double-1>", self.on_volume_select)

        self.info_label = tk.Label(self, text="", justify=tk.LEFT)
        self.info_label.pack(anchor="w")

        self.dir_tree = ttk.Treeview(self, columns=("Size", "Date Modified"))
        self.dir_tree.heading("#0", text="Name")
        self.dir_tree.heading("#1", text="Size")
        self.dir_tree.heading("#2", text="Date Modified")
        self.dir_tree.pack(expand=True, fill=tk.BOTH)
        self.dir_tree.bind("<Double-1>", self.on_file_double_click)
        self.dir_tree.bind("<Button-3>", self.on_file_right_click)

        self.menu_bar = tk.Menu(self)
        self.config(menu=self.menu_bar)
        
    def get_volumes(self):
        volumes = []
        for drive in range(65, 91):
            volume = chr(drive) + ":"
            if os.path.exists(volume) and FAT32.check_fat32(volume):
                volumes.append(volume)
        return volumes

    def on_volume_select(self, event):
        try:
            choice = self.volume_listbox.curselection()[0]
            volume_name = self.volumes[choice]
            if FAT32.check_fat32(volume_name):
                self.vol = FAT32(volume_name)
                self.current_volume = volume_name
                print(f"[DEBUG] Selected volume: {volume_name}")
                self.load_directory_tree(volume_name + "\\")
                
                volume_info = FAT32.get_volume_info(volume_name)
                fat_block_info = self.vol.get_fat_block_info()
                volume_info_message = (
                    f"Volume: {volume_info[0]}\n"
                    f"Label: {volume_info[1]}\n"
                    f"Total Space: {volume_info[2]} bytes\n"
                    f"Free Space: {volume_info[3]} bytes\n"
                    f"Free Space (MB): {volume_info[4]:.2f} MB\n"
                    f"Total Blocks: {fat_block_info[0]}\n"
                    f"Allocated Blocks: {fat_block_info[1]}\n"
                    f"Free Blocks: {fat_block_info[2]}\n"
                    f"Total Size (MB): {fat_block_info[3]:.2f} MB\n"
                    f"Allocated Size (MB): {fat_block_info[4]:.2f} MB\n"
                    f"Free Size (MB): {fat_block_info[5]:.2f} MB"
                )
                self.info_label.config(text=volume_info_message)
            else:
                messagebox.showerror("Error", "Selected volume is not FAT32")
        except Exception as e:
            messagebox.showerror("Error", str(e))

    def load_directory_tree(self, path):
        try:
            for item in self.dir_tree.get_children():
                self.dir_tree.delete(item)
            entries = self.vol.get_file_list(path)
            for entry in entries:
                self.dir_tree.insert("", "end", text=entry["name"], values=(entry["size"], entry["date_modified"]))
        except Exception as e:
            messagebox.showerror("Error", f"Failed to load directory tree: {str(e)}")

    def on_file_double_click(self, event):
        item = self.dir_tree.selection()[0]
        file_name = self.dir_tree.item(item, "text")
        if file_name == ".":
            # 忽略 "." 的任何按键操作
            return
        try:
            if file_name == "..":
                # 返回到上一级目录
                current_path = self.vol.get_cwd()
                parent_path = os.path.dirname(current_path.rstrip("\\"))
                self.load_directory_tree(parent_path)
                self.vol.change_dir(parent_path)
            else:
                file_entry = self.vol.RDET.find_entry(file_name)
                if file_entry.is_directory():
                    # 如果是目录，则打开目录
                    self.load_directory_tree(file_name)
                    self.vol.change_dir(file_name)
                else:
                    # 如果是文件，则查看文件内容
                    file_data = self.vol.get_file_content(file_name)
                    hex_data = file_data.hex()
                    self.show_hex_viewer(file_name, hex_data)
        except Exception as e:
            messagebox.showerror("Error", str(e))

    def on_file_right_click(self, event):
        item = self.dir_tree.selection()[0]
        file_name = self.dir_tree.item(item, "text")
        try:
            file_entry = self.vol.RDET.find_entry(file_name)
            cluster_chain = self.vol.FAT[0].get_cluster_chain(file_entry.start_cluster)
            cluster_info = "\n".join(map(str, cluster_chain))

            file_path = self.vol.get_cwd() + file_name
            last_modified = file_entry.date_updated
            file_size = file_entry.size
            file_permissions = file_entry.attr

            info_message = (
                f"Path: {file_path}\n"
                f"Last Modified: {last_modified}\n"
                f"Size: {file_size} bytes\n"
                f"Permissions: {file_permissions}\n"
                f"Allocated Blocks: \n{cluster_info}"
            )

            messagebox.showinfo("File Information", info_message)
        except Exception as e:
            messagebox.showerror("Error", str(e))

    def show_hex_viewer(self, file_name, hex_data):
        hex_viewer = tk.Toplevel(self)
        hex_viewer.title(f"Hex Viewer - {file_name}")

        text = tk.Text(hex_viewer, wrap="none")
        scroll_y = tk.Scrollbar(hex_viewer, orient="vertical", command=text.yview)
        scroll_x = tk.Scrollbar(hex_viewer, orient="horizontal", command=text.xview)
        text.configure(yscrollcommand=scroll_y.set, xscrollcommand=scroll_x.set)

        formatted_hex = self.format_hex(hex_data)
        text.insert("1.0", formatted_hex)
        text.pack(expand=True, fill=tk.BOTH, side=tk.LEFT)
        scroll_y.pack(fill=tk.Y, side=tk.RIGHT)
        scroll_x.pack(fill=tk.X, side=tk.BOTTOM)

    def format_hex(self, hex_data):
        lines = []
        for i in range(0, len(hex_data), 32):
            chunk = hex_data[i:i+32]
            hex_chunk = " ".join(chunk[j:j+2] for j in range(0, len(chunk), 2))
            ascii_chunk = "".join(chr(int(chunk[j:j+2], 16)) if 32 <= int(chunk[j:j+2], 16) <= 126 else '.' for j in range(0, len(chunk), 2))
            lines.append(f"{i:08X}  {hex_chunk:<48}  {ascii_chunk}")
        return "\n".join(lines)

if __name__ == "__main__":
    app = FAT32Browser()
    app.mainloop()
