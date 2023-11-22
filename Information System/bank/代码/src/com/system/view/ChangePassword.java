package com.system.view;

import com.system.entity.Card;
import com.system.entity.User;
import com.system.service.CardService;
import com.system.service.CardServiceImpl;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

public class ChangePassword extends JFrame {
	public boolean isPasswordAllZeros(String password) {
		return password.matches("^0+$");
	}
	private JPanel contentPane;
	private JTextField oldPassField;
	private JTextField moneyField;
	private JLabel nameLabel;
	private User user;
	private CardService cardService; // Assuming CardService is an interface and CardServiceImpl is its implementation

	public ChangePassword(Card card) {
		setTitle("修改密码");
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));

		cardService = new CardServiceImpl(); // Initialize the service

		JPanel centerPanel = new JPanel();
		centerPanel.setLayout(new GridLayout(5, 2, 10, 10)); // 5 rows, 2 cols, 10px hgap, 10px vgap
		centerPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
		contentPane.add(centerPanel, BorderLayout.CENTER);

		// Label "转账账户"
		JLabel lblOldPass = new JLabel("原密码：");
		lblOldPass.setFont(new Font("微软雅黑", Font.BOLD, 14));
		centerPanel.add(lblOldPass);

		// Text field for card name input
		oldPassField = new JPasswordField();
		oldPassField.setFont(new Font("微软雅黑", Font.PLAIN, 14));
		centerPanel.add(oldPassField);
		oldPassField.setColumns(10);

		// Label for displaying the name
		JLabel lblNawPass = new JLabel("新密码：");
		lblNawPass.setFont(new Font("微软雅黑", Font.BOLD, 14));
		centerPanel.add(lblNawPass);

		// Text field for card name input
		JTextField newPassField = new JPasswordField();
		newPassField.setFont(new Font("微软雅黑", Font.PLAIN, 14));
		centerPanel.add(newPassField);
		newPassField.setColumns(10);

		JLabel lblConfirm = new JLabel("再次输入：");
		lblConfirm.setFont(new Font("微软雅黑", Font.BOLD, 14));
		centerPanel.add(lblConfirm);

		JTextField newPassField2 = new JPasswordField();
		newPassField2.setFont(new Font("微软雅黑", Font.PLAIN, 14));
		centerPanel.add(newPassField2);
		newPassField2.setColumns(10);


		// Placeholder to adjust layout
		centerPanel.add(new JLabel(""));

		// Buttons panel
		JPanel buttonsPanel = new JPanel();
		contentPane.add(buttonsPanel, BorderLayout.SOUTH);

		// Confirm button
		JButton btnConfirm = new JButton("确认");
		btnConfirm.setFont(new Font("微软雅黑", Font.BOLD, 14));
		btnConfirm.addActionListener(e -> {
            String oldPassword = oldPassField.getText();
            String newPassword = newPassField.getText();
            String newPassword2 = newPassField2.getText();
            if ("".equals(oldPassword) || "".equals(newPassword) || "".equals(newPassword2)) {
                JOptionPane.showMessageDialog(null, "请输入完整的信息！");
            } else if (!newPassword.equals(newPassword2)) {
                JOptionPane.showMessageDialog(null, "两次输入的新密码不一致！");
            } else if (isPasswordAllZeros(newPassword)) {
                JOptionPane.showMessageDialog(null, "密码不能全为0！");
            } else if (newPassword.equals(oldPassword)) {
                JOptionPane.showMessageDialog(null, "新密码不能与旧密码相同！");
            } else {
                CardService cardService = new CardServiceImpl();
                boolean flag;
                try {
                    flag = cardService.updatePasswordById(card, oldPassword, newPassword);
                } catch (SQLException ex) {
                    throw new RuntimeException(ex);
                }
                if (flag) {
                    JOptionPane.showMessageDialog(null, "密码修改成功！");
                } else {
                    JOptionPane.showMessageDialog(null, "密码修改失败！");
                }
            }
        });
		buttonsPanel.add(btnConfirm);

		// Return button
		JButton btnReturn = new JButton("返回");
		btnReturn.setFont(new Font("微软雅黑", Font.BOLD, 14));
		btnReturn.addActionListener(e -> {
            ChangePassword.this.setVisible(false); // Close this window
        });
		buttonsPanel.add(btnReturn);
	}
}
