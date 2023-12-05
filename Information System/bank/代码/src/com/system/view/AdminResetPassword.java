package com.system.view;

import com.system.dao.UserDao;
import com.system.entity.Card;
import com.system.entity.User;
import com.system.service.CardService;
import com.system.service.CardServiceImpl;
import com.system.service.UserService;
import com.system.service.UserServiceImpl;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AdminResetPassword extends JFrame {
    public AdminResetPassword() {
        setTitle("修改密码");
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setBounds(100, 100, 450, 300);
        JPanel contentPane = new JPanel();

        setContentPane(contentPane);
        contentPane.setLayout(null);

        JLabel lblNewLabel = new JLabel("重置密码");
        lblNewLabel.setBounds(165, 10, 100, 30);
        contentPane.add(lblNewLabel);

        JLabel lblNewLabel_1 = new JLabel("卡号：");
        lblNewLabel_1.setBounds(100, 50, 100, 30);
        contentPane.add(lblNewLabel_1);

        JTextField usernameField = new JTextField();
        usernameField.setBounds(200, 50, 100, 30);
        contentPane.add(usernameField);
        usernameField.setColumns(10);

        JButton btnNewButton = new JButton("确认");
        btnNewButton.setBounds(100, 200, 100, 30);
        contentPane.add(btnNewButton);

        JButton btnNewButton_1 = new JButton("取消");
        btnNewButton_1.setBounds(200, 200, 100, 30);
        contentPane.add(btnNewButton_1);

        btnNewButton.addActionListener(e -> {
            String id = usernameField.getText();
            CardService cardService = new CardServiceImpl();
            User card = cardService.selectCardByCardName(id);
            if (card == null) {
                JOptionPane.showMessageDialog(null, "卡号不存在！", "错误", JOptionPane.ERROR_MESSAGE);
            } else {
                boolean flag;
                UserService userService = new UserServiceImpl();
                flag = userService.AdminResetUserByCid(Integer.parseInt(id));
                if (flag) {
                    JOptionPane.showMessageDialog(null, "重置密码成功！新密码为123456", "成功", JOptionPane.INFORMATION_MESSAGE);
                    dispose();
                } else {
                    JOptionPane.showMessageDialog(null, "重置密码失败！", "错误", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        btnNewButton_1.addActionListener(e -> dispose());

    }
}
