package com.system.view;

import java.awt.*;
import java.util.List;
import java.util.Vector;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;

import com.system.entity.Card;
import com.system.entity.Consumption;
import com.system.service.ConsumptionService;
import com.system.service.ConsumptionServiceImpl;

public class Transaction extends JFrame {
	private JPanel contentPane;
	private JTable table;
	private DefaultTableModel tableModel;
	private Card card;
	private ConsumptionService consumptionService = new ConsumptionServiceImpl();

	public Transaction(Card card) {
		this.card = card;

		setTitle("交易明细");
		setBounds(100, 100, 772, 456);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new BorderLayout(0, 0));

		createHeaderPanel();
		initializeTable();
		loadDataAndUpdateUI();
	}

	private void createHeaderPanel() {
		JPanel panelHeader = new JPanel();
		panelHeader.setBackground(Color.LIGHT_GRAY);
		contentPane.add(panelHeader, BorderLayout.NORTH);

		JLabel lblNewLabel = new JLabel("银行卡交易明细");
		lblNewLabel.setForeground(Color.WHITE);
		lblNewLabel.setFont(new Font("微软雅黑", Font.BOLD, 18));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		panelHeader.add(lblNewLabel);
	}

	private void initializeTable() {
		tableModel = new DefaultTableModel();
		tableModel.addColumn("交易类型");
		tableModel.addColumn("金额");
		tableModel.addColumn("时间");

		table = new JTable(tableModel);
		JScrollPane scrollPane = new JScrollPane(table);
		contentPane.add(scrollPane, BorderLayout.CENTER);
	}

	private void loadDataAndUpdateUI() {
		List<Consumption> list = consumptionService.selectByCid(card.getId());

		tableModel.setRowCount(0); // Clear existing data

		for (Consumption consumption : list) {
			Vector<Object> row = new Vector<>();
			row.add(consumption.getType());
			row.add(consumption.getPrice());
			row.add(consumption.getTime());
			tableModel.addRow(row);
		}

		tableModel.fireTableDataChanged(); // Notify the model that data has changed
	}

	public static void main(String[] args) {
		// Just for testing
		Card card = new Card(); // Make sure you initialize this
		EventQueue.invokeLater(() -> {
			try {
				Transaction frame = new Transaction(card);
				frame.setVisible(true);
			} catch (Exception e) {
				e.printStackTrace();
			}
		});
	}
}
