package com.system.view;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;

public class AdminMain extends JFrame {

    public static int gap = 28;
    private final JPanel contentPane;
    private final JPanel leftPanel;
    private final JPanel rightPanel;

    public AdminMain() {
        setTitle("银行管理系统");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(0, 0, 380, 280);

        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
        setContentPane(contentPane);
        contentPane.setLayout(new BorderLayout(10, 10)); // Use BorderLayout

        // Create the title panel at the top
        JPanel titlePanel = new JPanel();
        JLabel titleLabel = new JLabel("管理员，欢迎您！");
        titleLabel.setFont(new Font("华文行楷", Font.BOLD, 24));
        titlePanel.add(titleLabel);
        contentPane.add(titlePanel, BorderLayout.NORTH); // Add title panel to the top

        // Main panel which contains the left and right panels
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new GridLayout(1, 2, 10, 0)); // 1 row, 2 columns, horizontal gap 10

        leftPanel = new JPanel();
        leftPanel.setLayout(new GridBagLayout());
        GridBagConstraints gbcLeft = new GridBagConstraints();
        gbcLeft.gridwidth = GridBagConstraints.REMAINDER;
        gbcLeft.fill = GridBagConstraints.HORIZONTAL;
        gbcLeft.insets = new Insets(5, 5, 5, 5);

        rightPanel = new JPanel();
        rightPanel.setLayout(new GridBagLayout());
        GridBagConstraints gbcRight = new GridBagConstraints();
        gbcRight.gridwidth = GridBagConstraints.REMAINDER;
        gbcRight.fill = GridBagConstraints.HORIZONTAL;
        gbcRight.insets = new Insets(5, 5, 5, 5);

        // Add left and right panels to the main panel
        mainPanel.add(leftPanel);
        mainPanel.add(rightPanel);
        addServiceButton("冻结/解冻账户", new AdminFreeze(), gbcLeft, leftPanel);
        addSpacing(leftPanel, gbcLeft);
        addServiceButton("修改密码", new AdminResetPassword(), gbcLeft, leftPanel);
        addSpacing(leftPanel, gbcLeft);
        // Add the main panel to the center of the content pane
        contentPane.add(mainPanel, BorderLayout.CENTER);

        JButton btnExit = new JButton("退出系统");
        btnExit.setFont(new Font("微软雅黑", Font.BOLD, 16));
        btnExit.setBackground(Color.orange);
        btnExit.addActionListener((ActionEvent e) -> System.exit(0));
        rightPanel.add(btnExit, gbcRight);
    }

    private void addServiceButton(String title, JFrame newFrame, GridBagConstraints gbc, JPanel panel) {
        JButton button = new JButton(title);
        button.setFont(new Font("微软雅黑", Font.BOLD, 16));
        button.setBackground(Color.gray);
        button.addActionListener((ActionEvent e) -> {
            newFrame.setVisible(true);
        });
        panel.add(button, gbc);
    }

    // Helper method to add spacing in the grid
    private void addSpacing(JPanel panel, GridBagConstraints gbc) {
        JLabel label = new JLabel();
        label.setPreferredSize(new Dimension(100, gap));
        panel.add(label, gbc);
    }
}