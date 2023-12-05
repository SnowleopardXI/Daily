package com.system.view;

import com.system.entity.Card;
import com.system.entity.User;
import com.system.service.CardService;
import com.system.service.CardServiceImpl;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;

public class Register extends JFrame {

	public boolean isPasswordAllZeros(String password) {
		return password.matches("^0+$");
	}
	private JPanel contentPane;
	private JTextField usernameField;
	private JTextField sexField;
	private JTextField telephoneField;
	private JTextField cardnameField;
	private JPasswordField passwordField;
	private JPasswordField password2Field;

	public Register() {
		initialize();
	}

	private void initialize() {
		setTitle("银行系统用户注册");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 768, 502);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		GridBagLayout gbl_contentPane = new GridBagLayout();
		contentPane.setLayout(gbl_contentPane);

		JLabel lblNewLabel = new JLabel("用户注册");
		lblNewLabel.setFont(new Font("微软雅黑", Font.BOLD, 18));
		GridBagConstraints gbc_lblNewLabel = createGridBagConstraints(0, 0, 2, 1);
		contentPane.add(lblNewLabel, gbc_lblNewLabel);

		// 以下是添加组件的示例
		usernameField = new JTextField(20);
		JLabel lblNewLabel_1 = new JLabel("用户名：");
		lblNewLabel_1.setFont(new Font("微软雅黑", Font.BOLD, 15));
		addLabelAndComponent(lblNewLabel_1, usernameField, 1);

		sexField = new JTextField(20);
		JLabel lblNewLabel_2 = new JLabel("性别：");
		lblNewLabel_2.setFont(new Font("微软雅黑", Font.BOLD, 15));
		addLabelAndComponent(lblNewLabel_2, sexField, 2);

		telephoneField = new JTextField(20);
		JLabel lblNewLabel_3 = new JLabel("电话：");
		lblNewLabel_3.setFont(new Font("微软雅黑", Font.BOLD, 15));
		addLabelAndComponent(lblNewLabel_3, telephoneField, 3);

		cardnameField = new JTextField(20);
		JLabel lblNewLabel_4 = new JLabel("银行卡号：");
		lblNewLabel_4.setFont(new Font("微软雅黑", Font.BOLD, 15));
		addLabelAndComponent(lblNewLabel_4, cardnameField, 4);

		passwordField = new JPasswordField(20);
		JLabel lblNewLabel_5 = new JLabel("密码：");
		lblNewLabel_5.setFont(new Font("微软雅黑", Font.BOLD, 15));
		addLabelAndComponent(lblNewLabel_5, passwordField, 5);

		password2Field = new JPasswordField(20);
		JLabel lblNewLabel_6 = new JLabel("确认密码：");
		lblNewLabel_6.setFont(new Font("微软雅黑", Font.BOLD, 15));
		addLabelAndComponent(lblNewLabel_6, password2Field, 6);


		JButton btnNewButton = new JButton("注册");
		btnNewButton.setFont(new Font("微软雅黑", Font.BOLD, 14));
		GridBagConstraints gbc_btnNewButton = createGridBagConstraints(0, 7, 1, 1);
		btnNewButton.addActionListener(e -> registerUser());
		contentPane.add(btnNewButton, gbc_btnNewButton);

		JButton btnNewButton_1 = new JButton("返回");
		btnNewButton_1.setFont(new Font("微软雅黑", Font.BOLD, 14));
		GridBagConstraints gbc_btnNewButton_1 = createGridBagConstraints(1, 7, 1, 1);
		btnNewButton_1.addActionListener(e -> returnToLogin());
		contentPane.add(btnNewButton_1, gbc_btnNewButton_1);

		// 调整界面大小以适应内容
		pack();
		setLocationRelativeTo(null); // 居中显示
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

	private void registerUser() {
		String username = usernameField.getText();
		String sex = sexField.getText();
		String telephone = telephoneField.getText();
		String cardname = cardnameField.getText();
		String password = passwordField.getText();
		String passwords = password2Field.getText();
		CardService cardService = new CardServiceImpl();

		if ("".equals(username) || "".equals(sex) || "".equals(telephone) || "".equals(cardname)
				|| "".equals(password) || "".equals(passwords)) {
			JOptionPane.showMessageDialog(null, "请输入完整的信息！");
		} else if (!password.equals(passwords)) {
			JOptionPane.showMessageDialog(null, "两次输入的密码不一致！");
		} else if (cardService.selectIsRepeat(cardname)) {
			JOptionPane.showMessageDialog(null, "银行卡号已被注册，请修改！");
		} else if (isPasswordAllZeros(password))
		{
			JOptionPane.showMessageDialog(null, "密码不能全为0！");
		}
		else
		{
			Card card = new Card();
			card.setCardname(cardname);
			card.setPassword(password);
			User user = new User();
			user.setUsername(username);
			user.setSex(sex);
			user.setTelephone(telephone);
			boolean flag = cardService.insertCardAndUser(card, user);
			if (flag) {
				JOptionPane.showMessageDialog(null, "注册成功！");
			} else {
				JOptionPane.showMessageDialog(null, "注册失败！");
			}
		}
	}

	private void returnToLogin() {
		setVisible(false);
		new Login().setVisible(true);
	}

	public static void main(String[] args) {
		EventQueue.invokeLater(() -> {
			try {
				Register frame = new Register();
				frame.setVisible(true);
			} catch (Exception e) {
				e.printStackTrace();
			}
		});
	}
}
