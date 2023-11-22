package com.system.view;

import com.system.service.UserService;
import com.system.service.UserServiceImpl;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
public class AdminFreeze extends JFrame {
    private JPanel contentPane;

    public AdminFreeze() {
        setTitle("冻结账户");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(100, 100, 450, 300);
        contentPane = new JPanel();
        contentPane.setBackground(Color.WHITE);
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);

        GridBagLayout gbl_contentPane = new GridBagLayout();
        gbl_contentPane.columnWidths = new int[]{0, 0, 0, 0};
        gbl_contentPane.rowHeights = new int[]{0, 0, 0, 0, 0};
        gbl_contentPane.columnWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
        gbl_contentPane.rowWeights = new double[]{0.0, 0.0, 0.0, 1.0, Double.MIN_VALUE};
        contentPane.setLayout(gbl_contentPane);

        JLabel lblNewLabel = new JLabel("冻结/解冻账户");
        lblNewLabel.setFont(new Font("微软雅黑", Font.BOLD, 18));
        GridBagConstraints gbc_lblNewLabel = new GridBagConstraints();
        gbc_lblNewLabel.insets = new Insets(10, 10, 10, 10);
        gbc_lblNewLabel.gridx = 1;
        gbc_lblNewLabel.gridy = 0;
        contentPane.add(lblNewLabel, gbc_lblNewLabel);

        JLabel lblNewLabel_1 = new JLabel("账户ID：");
        lblNewLabel_1.setFont(new Font("微软雅黑", Font.PLAIN, 16));
        GridBagConstraints gbc_lblNewLabel_1 = new GridBagConstraints();
        gbc_lblNewLabel_1.insets = new Insets(10, 10, 10, 10);
        gbc_lblNewLabel_1.anchor = GridBagConstraints.EAST;
        gbc_lblNewLabel_1.gridx = 0;
        gbc_lblNewLabel_1.gridy = 1;
        contentPane.add(lblNewLabel_1, gbc_lblNewLabel_1);

        JTextField textField = new JTextField();
        GridBagConstraints gbc_textField = new GridBagConstraints();
        gbc_textField.insets = new Insets(10, 10, 10, 10);
        gbc_textField.fill = GridBagConstraints.HORIZONTAL;
        gbc_textField.gridx = 1;
        gbc_textField.gridy = 1;
        contentPane.add(textField, gbc_textField);
        textField.setColumns(10);

        JButton btnNewButton = new JButton("冻结");
        btnNewButton.setFont(new Font("微软雅黑", Font.PLAIN, 16));
        GridBagConstraints gbc_btnNewButton = new GridBagConstraints();
        gbc_btnNewButton.insets = new Insets(10, 10, 10, 10);
        gbc_btnNewButton.gridx = 1;
        gbc_btnNewButton.gridy = 2;
        contentPane.add(btnNewButton, gbc_btnNewButton);

        JButton btnNewButton_1 = new JButton("解冻");
        btnNewButton_1.setFont(new Font("微软雅黑", Font.PLAIN, 16));
        GridBagConstraints gbc_btnNewButton_1 = new GridBagConstraints();
        gbc_btnNewButton_1.insets = new Insets(10, 10, 10, 10);
        gbc_btnNewButton_1.gridx = 1;
        gbc_btnNewButton_1.gridy = 3;
        contentPane.add(btnNewButton_1, gbc_btnNewButton_1);

        btnNewButton.addActionListener(e -> {
            String id = textField.getText();
            if (id.isEmpty()) {
                JOptionPane.showMessageDialog(null, "请输入账户ID", "错误", JOptionPane.ERROR_MESSAGE);
                return;
            }
            if (id.matches("^0+$")) {
                JOptionPane.showMessageDialog(null, "账户ID不能为0", "错误", JOptionPane.ERROR_MESSAGE);
                return;
            }
            int result = JOptionPane.showConfirmDialog(null, "确定要冻结账户吗？", "提示", JOptionPane.YES_NO_OPTION);
            if (result == JOptionPane.YES_OPTION) {
                UserService userService = new UserServiceImpl();
                boolean user = userService.updateStatus(Integer.parseInt(id), 0);
                if (user) {
                    JOptionPane.showMessageDialog(null, "冻结成功", "提示", JOptionPane.INFORMATION_MESSAGE);
                } else {
                    JOptionPane.showMessageDialog(null, "冻结失败", "提示", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        btnNewButton_1.addActionListener(e -> {
            String id = textField.getText();
            if (id.isEmpty()) {
                JOptionPane.showMessageDialog(null, "请输入账户ID", "错误", JOptionPane.ERROR_MESSAGE);
                return;
            }
            if (id.matches("^0+$")) {
                JOptionPane.showMessageDialog(null, "账户ID不能为0", "错误", JOptionPane.ERROR_MESSAGE);
                return;
            }
            int result = JOptionPane.showConfirmDialog(null, "确定要解冻账户吗？", "提示", JOptionPane.YES_NO_OPTION);
            if (result == JOptionPane.YES_OPTION) {
                UserService userService = new UserServiceImpl();
                boolean user = userService.updateStatus(Integer.parseInt(id), 1);
                if (user) {
                    JOptionPane.showMessageDialog(null, "解冻成功", "提示", JOptionPane.INFORMATION_MESSAGE);
                } else {
                    JOptionPane.showMessageDialog(null, "解冻失败", "提示", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
    }
}
