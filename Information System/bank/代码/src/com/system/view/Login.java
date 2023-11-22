package com.system.view;

import com.system.entity.Card;
import com.system.service.CardService;
import com.system.service.CardServiceImpl;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Login extends JFrame {

	private JPanel contentPane;
	private JTextField cardField;
	private JPasswordField passwordField;

	public static void main(String[] args) {
		EventQueue.invokeLater(() -> {
            try {
                Login frame = new Login();
                frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
	}

	public Login() {
		setTitle("银行管理系统");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 780, 517); // You can also use setSize and setLocationRelativeTo(null);
		contentPane = new JPanel();
		contentPane.setBackground(Color.WHITE);
		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(10, 10)); // 使用 BorderLayout
		GridBagConstraints gbc = new GridBagConstraints();
		gbc.fill = GridBagConstraints.HORIZONTAL;
		gbc.insets = new Insets(10, 10, 10, 10);

		// 北部 Panel
		JPanel northPanel = new JPanel();
		northPanel.setBackground(SystemColor.gray);
		contentPane.add(northPanel, BorderLayout.NORTH);
		// 居中显示images/bank.jpg
		JLabel lblBankIcon = new JLabel(new ImageIcon(Login.class.getResource("/images/bank.jpg")));
		gbc.gridx = 4;
		gbc.gridy = 0;
		northPanel.add(lblBankIcon, gbc);

		JLabel lblTitle = new JLabel("银行账户管理系统");
		lblTitle.setForeground(SystemColor.black);
		lblTitle.setFont(new Font("华文行楷", Font.BOLD, 24));
		northPanel.add(lblTitle);

		// 中部 Panel 使用 GridBagLayout
		JPanel centerPanel = new JPanel(new GridBagLayout());
		contentPane.add(centerPanel, BorderLayout.CENTER);

		// 添加图标
		// 注意: 请确保图像路径是正确的，否则图像将不会显示
		JLabel lblCardIcon = new JLabel(new ImageIcon(Login.class.getResource("/images/card_icon.jpg")));
		gbc.gridx = 3;
		gbc.gridy = 0;
		centerPanel.add(lblCardIcon, gbc);

		JLabel lblPasswordIcon = new JLabel(new ImageIcon(Login.class.getResource("/images/password_icon.jpg")));
		gbc.gridx = 3;
		gbc.gridy = 1;
		centerPanel.add(lblPasswordIcon, gbc);

		JLabel lblCardNumber = new JLabel("银行卡号：");
		lblCardNumber.setFont(new Font("微软雅黑", Font.BOLD, 16));
		gbc.gridx = 4;
		gbc.gridy = 0;
		centerPanel.add(lblCardNumber, gbc);

		cardField = new JTextField(13);
		cardField.setFont(new Font("微软雅黑", Font.BOLD, 14));
		gbc.gridx = 5;
		gbc.gridy = 0;
		centerPanel.add(cardField, gbc);

		JLabel lblPassword = new JLabel("银行密码：");
		lblPassword.setFont(new Font("微软雅黑", Font.BOLD, 16));
		gbc.gridx = 4;
		gbc.gridy = 1;
		centerPanel.add(lblPassword, gbc);

		passwordField = new JPasswordField(10);
		passwordField.setFont(new Font("微软雅黑", Font.BOLD, 14));
		gbc.gridx = 5;
		gbc.gridy = 1;
		centerPanel.add(passwordField, gbc);

		JButton btnRegister = new JButton("注册");
		btnRegister.setFont(new Font("微软雅黑", Font.BOLD, 14));
		btnRegister.setBackground(Color.orange);
		btnRegister.setBounds(0, 0, 0, 0);
		gbc.gridx = 4;
		gbc.gridy = 3;
		centerPanel.add(btnRegister, gbc);

		JButton btnLogin = new JButton("登录");
		btnLogin.setFont(new Font("微软雅黑", Font.BOLD, 14));
		gbc.gridx = 5;
		gbc.gridy = 3;
		centerPanel.add(btnLogin, gbc);

		JButton btnAdmin = new JButton("管理员登录");
		btnAdmin.setFont(new Font("微软雅黑", Font.BOLD, 14));
		gbc.gridx = 3;
		gbc.gridy = 3;
		centerPanel.add(btnAdmin, gbc);

		// 按钮事件
		btnLogin.addActionListener(e -> {
			String cardName = cardField.getText();
			String password = passwordField.getText();
			if ("".equals(cardName) || "".equals(password)) {
				JOptionPane.showMessageDialog(null, "请输入完整信息！");
			} else {
				CardService cardService = new CardServiceImpl();
				Card card = cardService.login(cardName, password);
				if (card == null) {
					JOptionPane.showMessageDialog(null, "登录失败！");
				} else {
					setVisible(false);
					new MainUI(card).setVisible(true);
				}
			}
		});
		btnRegister.addActionListener(e -> {
			setVisible(false);
			new Register().setVisible(true);
		});

		btnAdmin.addActionListener(e -> {
            setVisible(false);
            new AdminLogin().setVisible(true);
        });
	}
}
