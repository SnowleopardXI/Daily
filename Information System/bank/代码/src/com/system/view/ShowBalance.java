package com.system.view;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.EmptyBorder;

import com.system.entity.Card;
import com.system.service.CardService;
import com.system.service.CardServiceImpl;

public class ShowBalance extends JFrame {

	private JPanel contentPane;
	private JLabel moneyLabel;

	public ShowBalance(Card card) {
		CardService cardService = new CardServiceImpl();
		Card card_new = cardService.selectCardById(card.getId());
		setTitle("显示余额");
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));

		JPanel panel = new JPanel();
		panel.setBackground(Color.WHITE);
		contentPane.add(panel, BorderLayout.CENTER);
		panel.setLayout(new GridBagLayout());

		GridBagConstraints gbc = new GridBagConstraints();
		gbc.gridwidth = GridBagConstraints.REMAINDER;
		gbc.anchor = GridBagConstraints.CENTER;
		gbc.insets = new Insets(10, 10, 10, 10);

		JLabel lblTitle = new JLabel("显示余额");
		lblTitle.setForeground(Color.BLACK);
		lblTitle.setFont(new Font("微软雅黑", Font.BOLD, 18));
		gbc.insets = new Insets(20, 10, 20, 10);
		panel.add(lblTitle, gbc);

		gbc.insets = new Insets(10, 10, 10, 10);
		moneyLabel = new JLabel();
		moneyLabel.setHorizontalAlignment(SwingConstants.CENTER);
		moneyLabel.setFont(new Font("微软雅黑", Font.BOLD, 16));
		panel.add(moneyLabel, gbc);

		moneyLabel.setText("您的余额为：" + card_new.getPrice() + "元");

		JPanel bottomPanel = new JPanel();
		bottomPanel.setBackground(Color.WHITE);
		contentPane.add(bottomPanel, BorderLayout.SOUTH);

		JButton btnReturn = new JButton("返回");
		btnReturn.addActionListener(e -> {
			dispose();
		});
		btnReturn.setFont(new Font("微软雅黑", Font.BOLD, 16));
		bottomPanel.add(btnReturn);
	}
}
