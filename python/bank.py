import tkinter as tk
from tkinter import messagebox
import pymysql

# Database connection
db = pymysql.connect(host="10.40.172.1",
                     user="user",
                     password="123456",
                     database="swing_bank")
cursor = db.cursor()

# Function to register a new user
def register_user():
    username = entry_username.get()
    password = entry_password.get()
    if username and password:
        try:
            cursor.execute("INSERT INTO users (username, password) VALUES (%s, %s)", (username, password))
            db.commit()
            messagebox.showinfo("Success", "Registration Successful")
        except pymysql.MySQLError as e:
            db.rollback()
            messagebox.showerror("Error", f"Error Occurred: {e}")
    else:
        messagebox.showwarning("Input Error", "Username and Password are required")

# Function to deposit money
def deposit():
    username = entry_username.get()
    amount = float(entry_amount.get())
    try:
        cursor.execute("UPDATE users SET balance = balance + %s WHERE username = %s", (amount, username))
        cursor.execute("INSERT INTO transactions (user_id, transaction_type, amount) VALUES ((SELECT user_id FROM users WHERE username = %s), 'Deposit', %s)", (username, amount))
        db.commit()
        messagebox.showinfo("Success", "Deposit Successful")
    except pymysql.MySQLError as e:
        db.rollback()
        messagebox.showerror("Error", f"Error Occurred: {e}")

# Function to withdraw money
def withdraw():
    username = entry_username.get()
    amount = float(entry_amount.get())
    try:
        cursor.execute("UPDATE users SET balance = balance - %s WHERE username = %s AND balance >= %s", (amount, username, amount))
        cursor.execute("INSERT INTO transactions (user_id, transaction_type, amount) VALUES ((SELECT user_id FROM users WHERE username = %s), 'Withdrawal', %s)", (username, amount))
        db.commit()
        messagebox.showinfo("Success", "Withdrawal Successful")
    except pymysql.MySQLError as e:
        db.rollback()
        messagebox.showerror("Error", f"Error Occurred: {e}")

# Function to transfer money
def transfer():
    from_user = entry_from_username.get()
    to_user = entry_to_username.get()
    amount = float(entry_amount.get())
    try:
        cursor.execute("UPDATE users SET balance = balance - %s WHERE username = %s AND balance >= %s", (amount, from_user, amount))
        cursor.execute("UPDATE users SET balance = balance + %s WHERE username = %s", (amount, to_user))
        cursor.execute("INSERT INTO transactions (user_id, transaction_type, amount) VALUES ((SELECT user_id FROM users WHERE username = %s), 'Transfer', %s)", (from_user, amount))
        cursor.execute("INSERT INTO transactions (user_id, transaction_type, amount) VALUES ((SELECT user_id FROM users WHERE username = %s), 'Received Transfer', %s)", (to_user, amount))
        db.commit()
        messagebox.showinfo("Success", "Transfer Successful")
    except pymysql.MySQLError as e:
        db.rollback()
        messagebox.showerror("Error", f"Error Occurred: {e}")

# Function to freeze/unfreeze account
def toggle_freeze():
    username = entry_username.get()
    try:
        cursor.execute("UPDATE users SET is_frozen = NOT is_frozen WHERE username = %s", (username,))
        db.commit()
        messagebox.showinfo("Success", "Account freeze status toggled")
    except pymysql.MySQLError as e:
        db.rollback()
        messagebox.showerror("Error", f"Error Occurred: {e}")

# Function to modify account information
def modify_account():
    username = entry_username.get()
    new_username = entry_new_username.get()
    new_password = entry_new_password.get()
    try:
        if new_username:
            cursor.execute("UPDATE users SET username = %s WHERE username = %s", (new_username, username))
        if new_password:
            cursor.execute("UPDATE users SET password = %s WHERE username = %s", (new_password, username))
        db.commit()
        messagebox.showinfo("Success", "Account information updated")
    except pymysql.MySQLError as e:
        db.rollback()
        messagebox.showerror("Error", f"Error Occurred: {e}")

# GUI setup
root = tk.Tk()
root.title("Banking System")

tk.Label(root, text="Username").grid(row=0, column=0)
tk.Label(root, text="Password").grid(row=1, column=0)
tk.Label(root, text="New Username").grid(row=2, column=0)
tk.Label(root, text="New Password").grid(row=3, column=0)
tk.Label(root, text="Amount").grid(row=4, column=0)
tk.Label(root, text="From Username").grid(row=5, column=0)
tk.Label(root, text="To Username").grid(row=6, column=0)

entry_username = tk.Entry(root)
entry_password = tk.Entry(root, show="*")
entry_new_username = tk.Entry(root)
entry_new_password = tk.Entry(root, show="*")
entry_amount = tk.Entry(root)
entry_from_username = tk.Entry(root)
entry_to_username = tk.Entry(root)

entry_username.grid(row=0, column=1)
entry_password.grid(row=1, column=1)
entry_new_username.grid(row=2, column=1)
entry_new_password.grid(row=3, column=1)
entry_amount.grid(row=4, column=1)
entry_from_username.grid(row=5, column=1)
entry_to_username.grid(row=6, column=1)

tk.Button(root, text="Register", command=register_user).grid(row=7, column=0)
tk.Button(root, text="Deposit", command=deposit).grid(row=7, column=1)
tk.Button(root, text="Withdraw", command=withdraw).grid(row=8, column=0)
tk.Button(root, text="Transfer", command=transfer).grid(row=8, column=1)
tk.Button(root, text="Freeze/Unfreeze Account", command=toggle_freeze).grid(row=9, column=0)
tk.Button(root, text="Modify Account", command=modify_account).grid(row=9, column=1)

root.mainloop()

# Close the database connection when the app is closed
db.close()
