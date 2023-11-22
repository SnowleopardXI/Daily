package com.system.view;

import java.awt.*;
import javax.swing.*;
import javax.swing.border.EmptyBorder;

import com.system.entity.Card;
import com.system.entity.User;
import com.system.service.UserService;
import com.system.service.UserServiceImpl;

public class UserInfo extends JFrame {

	private JTextField usernameField;
	private JTextField sexField;
	private JTextField telephoneField;

	public UserInfo(Card card) {
		setTitle("查询/编辑个人信息");
		setBounds(100, 100, 565, 324);

		JPanel contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 10));
		setContentPane(contentPane);
		GridBagConstraints gbc = new GridBagConstraints();
		gbc.fill = GridBagConstraints.HORIZONTAL;
		gbc.insets = new Insets(10, 10, 10, 10);

		UserService userService = new UserServiceImpl();
		User user = userService.selectUserByCid(card.getId());

		// Header label
		JLabel lblHeader = new JLabel("查询/编辑个人信息", SwingConstants.CENTER);
		lblHeader.setForeground(Color.BLACK);
		lblHeader.setFont(new Font("微软雅黑", Font.BOLD, 18));
		contentPane.add(lblHeader, BorderLayout.NORTH);

		// Center panel for form fields
		JPanel centerPanel = new JPanel();
		centerPanel.setLayout(new GridLayout(3, 2, 10, 10)); // GridLayout for form fields
		contentPane.add(centerPanel, BorderLayout.CENTER);

		// Username field
		JLabel lblUsername = new JLabel("用户名：", SwingConstants.CENTER);
		centerPanel.add(lblUsername);
		lblUsername.setFont(new Font("微软雅黑", Font.PLAIN, 16));
		usernameField = new JTextField(user.getUsername());
		centerPanel.add(usernameField);

		// Sex field
		JLabel lblsex = new JLabel("性别：", SwingConstants.CENTER);
		centerPanel.add(lblsex);
		lblsex.setFont(new Font("微软雅黑", Font.PLAIN, 16));
		sexField = new JTextField(user.getSex());
		centerPanel.add(sexField);

		// Telephone field
		JLabel lblTelephone = new JLabel("电话：", SwingConstants.CENTER);
		centerPanel.add(lblTelephone);
		lblTelephone.setFont(new Font("微软雅黑", Font.PLAIN, 16));
		telephoneField = new JTextField(user.getTelephone());
		centerPanel.add(telephoneField);

		JPanel bottomPanel = new JPanel();
		bottomPanel.setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));
		contentPane.add(bottomPanel, BorderLayout.SOUTH);

		// Save button
		JButton btnSave = new JButton("保存");
		btnSave.addActionListener(e -> {
			String username = usernameField.getText();
			String sex = sexField.getText();
			String telephone = telephoneField.getText();
			if ("".equals(username) || "".equals(sex) || "".equals(telephone)) {
				JOptionPane.showMessageDialog(null, "请输入完整的信息！");
			} else {
				User updatedUser = new User();
				updatedUser.setId(card.getId()); // Assuming User entity has this method
				updatedUser.setUsername(username);
				updatedUser.setSex(sex);
				updatedUser.setTelephone(telephone);
				boolean flag = userService.updateUserByCid(card.getId(), updatedUser);
				if (flag) {
					JOptionPane.showMessageDialog(this, "信息已保存。");
				} else {
					JOptionPane.showMessageDialog(this, "信息保存失败，请重试。");
				}
				setVisible(false);
			}
		});
		bottomPanel.add(btnSave);

		// Return button
		JButton btnReturn = new JButton("返回");
		btnReturn.addActionListener(e -> UserInfo.this.setVisible(false));
		bottomPanel.add(btnReturn);

	}

}
