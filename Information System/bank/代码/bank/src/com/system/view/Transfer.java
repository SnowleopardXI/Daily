package com.system.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.border.EmptyBorder;

import com.system.entity.Card;
import com.system.entity.User;
import com.system.service.CardService;
import com.system.service.CardServiceImpl;

public class Transfer extends JFrame {

	private JPanel contentPane;
	private JTextField cardNameField;
	private JTextField moneyField;
	private JLabel nameLabel;
	private User user;
	private CardService cardService; // Assuming CardService is an interface and CardServiceImpl is its implementation

	public Transfer(Card card) {
		setTitle("转账业务");
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
		JLabel lblCardName = new JLabel("转账账户：");
		lblCardName.setFont(new Font("微软雅黑", Font.BOLD, 14));
		centerPanel.add(lblCardName);

		// Text field for card name input
		cardNameField = new JTextField();
		cardNameField.setFont(new Font("微软雅黑", Font.PLAIN, 14));
		centerPanel.add(cardNameField);
		cardNameField.setColumns(10);

		// Label for displaying the name
		JLabel lblName = new JLabel("姓名：");
		lblName.setFont(new Font("微软雅黑", Font.BOLD, 14));
		centerPanel.add(lblName);

		// Label for showing the name after querying
		nameLabel = new JLabel("");
		nameLabel.setFont(new Font("微软雅黑", Font.PLAIN, 14));
		centerPanel.add(nameLabel);

		// Label "转账金额"
		JLabel lblTransferAmount = new JLabel("转账金额：");
		lblTransferAmount.setFont(new Font("微软雅黑", Font.BOLD, 14));
		centerPanel.add(lblTransferAmount);

		// Text field for amount input
		moneyField = new JTextField();
		moneyField.setFont(new Font("微软雅黑", Font.PLAIN, 14));
		centerPanel.add(moneyField);
		moneyField.setColumns(10);

		// Format notice label
		JLabel lblFormatNotice = new JLabel("注意格式：0.00");
		lblFormatNotice.setForeground(Color.RED);
		lblFormatNotice.setFont(new Font("微软雅黑", Font.PLAIN, 12));
		centerPanel.add(lblFormatNotice);

		// Placeholder to adjust layout
		centerPanel.add(new JLabel(""));

		// Buttons panel
		JPanel buttonsPanel = new JPanel();
		contentPane.add(buttonsPanel, BorderLayout.SOUTH);

		// Query button
		JButton btnQuery = new JButton("查询");
		btnQuery.setFont(new Font("微软雅黑", Font.BOLD, 14));
		btnQuery.addActionListener(e -> {
            String cardName = cardNameField.getText();
            if ("".equals(cardName)) {
                JOptionPane.showMessageDialog(null, "银行卡号不能为空！");
            } else {
                // Use the instance 'cardService' to call the method
                user = cardService.selectCardByCardName(cardName);
                if (user == null) {
                    JOptionPane.showMessageDialog(null, "该银行卡号不存在！");
                } else {
                    // 查询银行卡是否为自己
                    if (card.getId() == user.getC_id()) {
                        JOptionPane.showMessageDialog(null, "不能转账给自己！");
                        return;
                    }
                    nameLabel.setText(user.getUsername());
                }
            }
        });
		buttonsPanel.add(btnQuery); // Add query button to the buttons panel

		// Confirm button
		JButton btnConfirm = new JButton("确认");
		btnConfirm.setFont(new Font("微软雅黑", Font.BOLD, 14));
		btnConfirm.addActionListener(e -> {
            String money = moneyField.getText();
            btnQuery.doClick(); // Simulate a click on the query button
            // 查询银行卡是否为自己
            if (card.getId() == user.getC_id()) {
                JOptionPane.showMessageDialog(null, "不能转账给自己！");
                return;
            }
            if (money.matches(".*[a-zA-Z]+.*")) {
                JOptionPane.showMessageDialog(null, "输入的金额不能包含非数字字符！");
            }else if (money.contains("-")) {
                JOptionPane.showMessageDialog(null, "输入的金额不能为负数！");
            } else if (money.isEmpty()) {
                JOptionPane.showMessageDialog(null, "请输入转账金额！");
            } else {
                boolean flag = cardService.TransferMoney(card.getId(), user.getC_id(), money);
                boolean flag1 = cardService.IsValid(cardNameField.getText());
                if (!flag1) {
                    JOptionPane.showMessageDialog(null, "该银行卡号已被冻结！");
                    return;
                }
                if (flag) {
                    JOptionPane.showMessageDialog(null, "转账成功！");
                    dispose();
                } else {
                    JOptionPane.showMessageDialog(null, "余额不足，转账失败！");
                }
            }
        });
		buttonsPanel.add(btnConfirm);

		// Return button
		JButton btnReturn = new JButton("返回");
		btnReturn.setFont(new Font("微软雅黑", Font.BOLD, 14));
		btnReturn.addActionListener(e -> dispose());
		buttonsPanel.add(btnReturn);


	}
}