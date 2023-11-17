package com.system.view;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

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

public class Deposit extends JFrame {

	private JPanel contentPane;
	private JTextField moneyField;

	/**
	 * Launch the application.
	 */
	// public static void main(String[] args) {
	// EventQueue.invokeLater(new Runnable() {
	// public void run() {
	// try {
	// Withdraw frame = new Withdraw();
	// frame.setVisible(true);
	// } catch (Exception e) {
	// e.printStackTrace();
	// }
	// }
	// });
	// }

	/**
	 * Create the frame.
	 */
	public Deposit(Card card) {
		setTitle("存款业务");
		setBounds(100, 100, 450, 248);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		JPanel panel = new JPanel();
		panel.setBackground(Color.WHITE);
		panel.setBounds(0, 0, 434, 214);
		contentPane.add(panel);
		panel.setLayout(null);

		JLabel lblNewLabel = new JLabel("存款业务");
		lblNewLabel.setForeground(Color.WHITE);
		lblNewLabel.setFont(new Font("微软雅黑", Font.BOLD, 18));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(125, 20, 158, 40);
		panel.add(lblNewLabel);

		JLabel lblNewLabel_1 = new JLabel("存款金额：");
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

		JButton btnNewButton = new JButton("确定");
		btnNewButton.addActionListener(e -> {
            String money = moneyField.getText();
            // 判断输入的金额是否为非数字
            if (money.matches(".*[a-zA-Z]+.*")) {
                JOptionPane.showMessageDialog(null, "输入的金额不能包含非数字字符！");
            }else if(money.isEmpty()){
                JOptionPane.showMessageDialog(null, "请输入完整的信息！");
            }else{
                ConsumptionService consumptionService = new ConsumptionServiceImpl();
                boolean flag = consumptionService.insertConsumption(card, money);
                if (flag) {
                    JOptionPane.showMessageDialog(null, "存储成功！");
                    // 销毁当前窗口
                    dispose();
                } else {
                    JOptionPane.showMessageDialog(null, "存储失败！");
                }
            }
        });
		btnNewButton.setFont(new Font("微软雅黑", Font.BOLD, 15));
		btnNewButton.setBounds(61, 141, 93, 40);
		panel.add(btnNewButton);

		JButton btnNewButton_1 = new JButton("返回");
		btnNewButton_1.addActionListener(e -> {
            // 销毁当前窗口
            dispose();
        });
		btnNewButton_1.setFont(new Font("微软雅黑", Font.BOLD, 15));
		btnNewButton_1.setBounds(271, 141, 93, 40);
		panel.add(btnNewButton_1);

		JLabel lblNewLabel_2 = new JLabel("注意格式：0.00");
		lblNewLabel_2.setFont(new Font("微软雅黑", Font.BOLD, 13));
		lblNewLabel_2.setForeground(Color.RED);
		lblNewLabel_2.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_2.setBounds(149, 113, 158, 15);
		panel.add(lblNewLabel_2);
	}

}
