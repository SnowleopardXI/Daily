package com.system.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;

import com.system.entity.Card;
import com.system.service.ConsumptionService;
import com.system.service.ConsumptionServiceImpl;

public class Withdraw extends JFrame {

	private JPanel contentPane;
	private JTextField moneyField;

	/**
	 * Create the frame.
	 */
	public Withdraw(Card card) {
		setTitle("取款业务");
		setBounds(100, 100, 450, 300); // Increased the height to better fit components
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0)); // Set BorderLayout manager

		JPanel panel = new JPanel();
		panel.setBackground(Color.WHITE);
		contentPane.add(panel, BorderLayout.CENTER); // Add to the center region
		panel.setLayout(null);

		JLabel lblNewLabel = new JLabel("取款业务");
		lblNewLabel.setForeground(Color.BLACK); // Changed to BLACK to be visible on a white background
		lblNewLabel.setFont(new Font("微软雅黑", Font.BOLD, 18));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(125, 20, 158, 40);
		panel.add(lblNewLabel);

		JLabel lblNewLabel_1 = new JLabel("取款金额：");
		lblNewLabel_1.setFont(new Font("微软雅黑", Font.BOLD, 15));
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(60, 70, 94, 33);
		panel.add(lblNewLabel_1);

		moneyField = new JTextField();
		moneyField.setFont(new Font("微软雅黑", Font.BOLD, 15));
		moneyField.setBounds(149, 70, 158, 33);
		panel.add(moneyField);
		moneyField.setColumns(10);

		JLabel lblNewLabel_1_1 = new JLabel("元");
		lblNewLabel_1_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1_1.setFont(new Font("微软雅黑", Font.BOLD, 15));
		lblNewLabel_1_1.setBounds(315, 70, 49, 33);
		panel.add(lblNewLabel_1_1);

		JLabel lblNewLabel_2 = new JLabel("注意格式：0.00");
		lblNewLabel_2.setFont(new Font("微软雅黑", Font.BOLD, 13));
		lblNewLabel_2.setForeground(Color.RED);
		lblNewLabel_2.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_2.setBounds(149, 113, 158, 15);
		panel.add(lblNewLabel_2);

		JPanel buttonPanel = new JPanel(); // Create a new panel for buttons
		contentPane.add(buttonPanel, BorderLayout.SOUTH); // Add to the south region

		JButton btnNewButton = new JButton("确定");
		btnNewButton.addActionListener(e -> {
            String money = moneyField.getText();
            // 判断输入是否包括非数字字符
            if (money.matches(".*[a-zA-Z]+.*")) {
                JOptionPane.showMessageDialog(null, "输入的金额不能包含非数字字符！");
            }else if (money.contains("-")) {
                JOptionPane.showMessageDialog(null, "输入的金额不能为负数！");
            } else
            if (money.isEmpty()) {
                JOptionPane.showMessageDialog(null, "请输入完整的信息！");
            } else {
                ConsumptionService consumptionService = new ConsumptionServiceImpl();
                boolean flag = consumptionService.Withdraw(card, money);
                if (flag) {
                    JOptionPane.showMessageDialog(null, "取款成功！");
                    dispose();
                } else {
                    JOptionPane.showMessageDialog(null, "余额不足！");
                }
            }
        });
		btnNewButton.setFont(new Font("微软雅黑", Font.BOLD, 15));
		buttonPanel.add(btnNewButton); // Add to button panel

		JButton btnNewButton_1 = new JButton("返回");
		btnNewButton_1.addActionListener(e -> dispose());
		btnNewButton_1.setFont(new Font("微软雅黑", Font.BOLD, 15));
		buttonPanel.add(btnNewButton_1); // Add to button panel
	}
}
