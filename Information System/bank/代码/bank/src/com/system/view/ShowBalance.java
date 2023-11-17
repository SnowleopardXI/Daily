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
	private final CardService cardService;
	private Card card;

	public ShowBalance(Card card) {
		this.card = card;
		cardService = new CardServiceImpl();
		setTitle("显示余额");
		setBounds(100, 100, 450, 300);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);  // 设置默认关闭操作
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

		updateBalance();  // 初始时更新余额

		JPanel bottomPanel = new JPanel();
		bottomPanel.setBackground(Color.WHITE);
		contentPane.add(bottomPanel, BorderLayout.SOUTH);

		JButton btnUpdate = new JButton("更新");
		btnUpdate.addActionListener(e -> updateBalance());
		btnUpdate.setFont(new Font("微软雅黑", Font.BOLD, 16));
		bottomPanel.add(btnUpdate);

		JButton btnReturn = new JButton("返回");
		btnReturn.addActionListener(e -> setVisible(false));
		btnReturn.setFont(new Font("微软雅黑", Font.BOLD, 16));
		bottomPanel.add(btnReturn);
	}

	// 创建一个新方法来更新余额显示
	public void updateBalance() {
		Card card_new = cardService.selectCardById(card.getId());
		moneyLabel.setText("账户余额：" + card_new.getPrice() + "   元");
	}
}
