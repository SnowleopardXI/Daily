package com.system.dao;

import com.system.entity.Card;
import com.system.entity.Consumption;
import com.system.utils.DB;

import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ConsumptionDaoImpl implements ConsumptionDao {
	private Connection connection;
	private PreparedStatement ps;
	private ResultSet rs;

	@Override
	public int insertConsumption(Card card, String money) {
		String sql = "insert into consumption(c_id,type,price) values(?,?,?)";
		connection = new DB().getConnection();
		int flag = 0;
		try {
			connection.setAutoCommit(false);
			ps = connection.prepareStatement(sql);
			ps.setInt(1, card.getId());
			ps.setString(2, "存款");
			ps.setBigDecimal(3, new BigDecimal(money));
			flag = ps.executeUpdate();

			// 查询当前余额
			String sql_2 = "select * from card where id = ?";
			ps = connection.prepareStatement(sql_2);
			ps.setInt(1, card.getId());
			rs = ps.executeQuery();
			Card c = null;
			while (rs.next()) {
				c = new Card();
				c.setPrice(rs.getBigDecimal("price"));
			}

			String sql_1 = "update card set price = ? where id = ?";
			ps = connection.prepareStatement(sql_1);
            assert c != null;
            ps.setBigDecimal(1, new BigDecimal(money).add(c.getPrice()));
			ps.setInt(2, card.getId());
			flag = ps.executeUpdate();

			connection.commit();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			try {
				connection.rollback();
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			e.printStackTrace();
		}
		return flag;
	}

	@Override
	public int quMoney(Card card, String money) {
		String sql = "insert into consumption(c_id,type,price) values(?,?,?)";
		connection = new DB().getConnection();
		int flag = 0;
		try {
			connection.setAutoCommit(false);
			// 查询余额
			String sql_2 = "select * from card where id = ?";
			ps = connection.prepareStatement(sql_2);
			ps.setInt(1, card.getId());
			rs = ps.executeQuery();
			Card c = null;
			while (rs.next()) {
				c = new Card();
				c.setPrice(rs.getBigDecimal("price"));
				
			}
            assert c != null;
            if (c.getPrice().compareTo(new BigDecimal(money)) < 0) {
				return flag;
			} else {
				ps = connection.prepareStatement(sql);
				ps.setInt(1, card.getId());
				ps.setString(2, "取款");
				ps.setBigDecimal(3, new BigDecimal(money));
				flag = ps.executeUpdate();

				String sql_1 = "update card set price = ? where id = ?";
				ps = connection.prepareStatement(sql_1);
				ps.setBigDecimal(1, c.getPrice().subtract(new BigDecimal(money)));
				ps.setInt(2, card.getId());
				flag = ps.executeUpdate();
			}



			connection.commit();
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			try {
				connection.rollback();
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			e.printStackTrace();
		}
		return flag;
	}

	@Override
	public List<Consumption> selectByCid(int id) {
		String sql = "select * from consumption where c_id = ? order by time desc";
		connection = new DB().getConnection();
		List<Consumption> list = new ArrayList<>();
		try {
			ps = connection.prepareStatement(sql);
			ps.setInt(1, id);
			rs = ps.executeQuery();
			while (rs.next()) {
				Consumption consumption = new Consumption();
				consumption.setType(rs.getString("type"));
				consumption.setPrice(rs.getBigDecimal("price"));
				consumption.setTime(rs.getString("time"));
				list.add(consumption);
			}
			connection.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return list;
	}

}
