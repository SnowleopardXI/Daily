package com.system.view;

import com.system.entity.User;
import com.system.service.UserService;
import com.system.service.UserServiceImpl;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;

public class AdminLogin extends JFrame {
    private JPanel contentPane;
    private JTextField usernameField;
    private JPasswordField passwordField;
    public AdminLogin() {
        initialize();
    }

    public boolean isPasswordAllZeros(String password) {
        return password.matches("^0+$");
    }

    private GridBagConstraints createGridBagConstraints(int gridx, int gridy, int gridwidth, int gridheight) {
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.gridx = gridx;
        gbc.gridy = gridy;
        gbc.gridwidth = gridwidth;
        gbc.gridheight = gridheight;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(10, 10, 10, 10);
        return gbc;
    }

    private void addLabelAndComponent(JLabel label, JComponent component, int row) {
        GridBagConstraints gbc_label = createGridBagConstraints(0, row, 1, 1);
        GridBagConstraints gbc_component = createGridBagConstraints(1, row, 2, 1);
        contentPane.add(label, gbc_label);
        contentPane.add(component, gbc_component);
    }

    private void initialize() {
        setTitle("银行管理员登录");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 350, 300);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        GridBagLayout gbl_contentPane = new GridBagLayout();
        contentPane.setLayout(gbl_contentPane);

        JLabel lblNewLabel = new JLabel("管理员登录");
        lblNewLabel.setFont(new Font("微软雅黑", Font.BOLD, 18));
        GridBagConstraints gbc_lblNewLabel = createGridBagConstraints(0, 0, 2, 1);
        contentPane.add(lblNewLabel, gbc_lblNewLabel);

        // 以下是添加组件的示例
        usernameField = new JTextField(20);
        JLabel lblNewLabel_1 = new JLabel("管理员ID：");
        lblNewLabel_1.setFont(new Font("微软雅黑", Font.BOLD, 15));
        addLabelAndComponent(lblNewLabel_1, usernameField, 1);

        passwordField = new JPasswordField(20);
        JLabel lblNewLabel_2 = new JLabel("密码：");
        lblNewLabel_2.setFont(new Font("微软雅黑", Font.BOLD, 15));
        addLabelAndComponent(lblNewLabel_2, passwordField, 2);

        JButton btnAdmin = new JButton("登录");
        btnAdmin.setFont(new Font("微软雅黑", Font.BOLD, 14));
        GridBagConstraints gbc_btnAdmin = createGridBagConstraints(1, 3, 1, 1);
        contentPane.add(btnAdmin, gbc_btnAdmin);

        btnAdmin.addActionListener(e -> {
            String username = usernameField.getText();
            String password = passwordField.getText();
            if (isPasswordAllZeros(password)) {
                JOptionPane.showMessageDialog(null, "密码不能全为0！");
            } else if ("".equals(username) || "".equals(password)) {
                JOptionPane.showMessageDialog(null, "请输入完整信息！");
            } else {
                UserService userService = new UserServiceImpl();
                User user = userService.selectAdminByCid(username, password);
                if (user == null) {
                    JOptionPane.showMessageDialog(null, "登录失败！");
                } else {
                    JOptionPane.showMessageDialog(null, "登录成功！");
                    dispose();
                    new AdminMain().setVisible(true);
                }
            }
        });
    }
}