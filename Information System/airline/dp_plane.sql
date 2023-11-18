/*
Navicat MySQL Data Transfer

Source Server         : 本地数据库
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : dp_plane

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2018-02-06 15:56:47
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `bank`
-- ----------------------------
DROP TABLE IF EXISTS `bank`;
CREATE TABLE `bank` (
  `B_ID` decimal(8,0) NOT NULL,
  `B_NAME` varchar(30) NOT NULL,
  `B_U_NAME` varchar(20) NOT NULL,
  `B_U_CARD` varchar(20) DEFAULT NULL,
  `B_ACCOUNT` varchar(20) DEFAULT NULL,
  `B_BALANCE` varchar(20) NOT NULL,
  PRIMARY KEY (`B_ID`),
  KEY `AK_Key_2` (`B_U_CARD`),
  KEY `AK_Key_3` (`B_ACCOUNT`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of bank
-- ----------------------------
INSERT INTO `bank` VALUES ('1', '中国银行', '马俐娜', '430421199110083713', '6222021913002785906', '92520.0');
INSERT INTO `bank` VALUES ('2', '中国邮政银行', '欧阳健', '430421199110083710', '6222021913002776580', '100000');
INSERT INTO `bank` VALUES ('3', '中国工商银行', '刘程', '430421199110083718', '62220219130003300133', '5000');
INSERT INTO `bank` VALUES ('4', '中国建设银行', '秦国文', '430421199110083715', '6222021913002200122', '15000');
INSERT INTO `bank` VALUES ('5', '中国银行', '明礼馨德', '622921199104052624', '622921199104052624', '6221322.0');

-- ----------------------------
-- Table structure for `deal_log`
-- ----------------------------
DROP TABLE IF EXISTS `deal_log`;
CREATE TABLE `deal_log` (
  `D_NUMBER` decimal(8,0) NOT NULL,
  `D_UID` varchar(20) DEFAULT NULL,
  `D_OPERTYPE` varchar(20) DEFAULT NULL,
  `D_TID` varchar(100) DEFAULT NULL,
  `D_TIME` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`D_NUMBER`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of deal_log
-- ----------------------------

-- ----------------------------
-- Table structure for `flight_addr`
-- ----------------------------
DROP TABLE IF EXISTS `flight_addr`;
CREATE TABLE `flight_addr` (
  `a_id` varchar(20) NOT NULL,
  `a_city` varchar(20) NOT NULL,
  `a_air` varchar(50) NOT NULL,
  PRIMARY KEY (`a_id`),
  UNIQUE KEY `a_air` (`a_air`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of flight_addr
-- ----------------------------
INSERT INTO `flight_addr` VALUES ('ct102', '长沙', '黄花机场');
INSERT INTO `flight_addr` VALUES ('ct103', '怀化', '芷江机场');
INSERT INTO `flight_addr` VALUES ('ct104', '北京', '北京首都国际机场');
INSERT INTO `flight_addr` VALUES ('ct105', '北京', '北京南苑国际机场');

-- ----------------------------
-- Table structure for `flight_info`
-- ----------------------------
DROP TABLE IF EXISTS `flight_info`;
CREATE TABLE `flight_info` (
  `F_NUMBER` varchar(30) NOT NULL,
  `F_TYPE` varchar(20) NOT NULL,
  `F_START_TIME` varchar(40) NOT NULL,
  `F_END_TIME` varchar(40) NOT NULL,
  `F_START` varchar(20) NOT NULL,
  `F_END` varchar(20) NOT NULL,
  `F_COMPANY` varchar(30) NOT NULL,
  PRIMARY KEY (`F_NUMBER`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of flight_info
-- ----------------------------
INSERT INTO `flight_info` VALUES ('CA1893', 'C1024', '07:00', '09:20', 'ct102', 'ct103', '中国国际航空');
INSERT INTO `flight_info` VALUES ('CA1894', 'C1024', '13:35', '15:55', 'ct103', 'ct102', '中国国际航空');
INSERT INTO `flight_info` VALUES ('CZ3809', 'H78', '10:20', '12:40', 'ct101', 'ct104', '南方航空');
INSERT INTO `flight_info` VALUES ('CZ3810', 'H78', '15:00', '17:20', 'ct104', 'ct101', '南方航空');
INSERT INTO `flight_info` VALUES ('MU5331', 'M736', '08:00', '10:36', 'ct101', 'ct103', '东方航空');
INSERT INTO `flight_info` VALUES ('MU5332', 'M736', '13:00', '15:36', 'ct103', 'ct101', '东方航空');
INSERT INTO `flight_info` VALUES ('MU5367', 'M738', '09:00', '09:25', 'ct101', 'ct102', '东方航空');
INSERT INTO `flight_info` VALUES ('MU5368', 'M738', '14:00', '14:25', 'ct102', 'ct101', '东方航空');

-- ----------------------------
-- Table structure for `orders`
-- ----------------------------
DROP TABLE IF EXISTS `orders`;
CREATE TABLE `orders` (
  `O_ID` varchar(100) DEFAULT NULL,
  `O_UID` varchar(20) DEFAULT NULL,
  `O_TID` varchar(40) DEFAULT NULL,
  `O_TIME` varchar(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of orders
-- ----------------------------
INSERT INTO `orders` VALUES ('O2657', 'malina', null, '2018-02-06');
INSERT INTO `orders` VALUES ('O262', 'malina', 'e1318', '2018-02-06');
INSERT INTO `orders` VALUES ('O6165', 'llq', 'e9605', '2018-02-06');

-- ----------------------------
-- Table structure for `seat`
-- ----------------------------
DROP TABLE IF EXISTS `seat`;
CREATE TABLE `seat` (
  `F_NUMBER` varchar(20) DEFAULT NULL,
  `S_TYPE` varchar(30) NOT NULL,
  `S_NUMBER` varchar(10) NOT NULL,
  `S_PRICE` decimal(10,2) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of seat
-- ----------------------------
INSERT INTO `seat` VALUES ('MU5367', '商务舱', '30', '120.00');
INSERT INTO `seat` VALUES ('MU5367', '经济舱', '80', '100.00');
INSERT INTO `seat` VALUES ('MU5367', '头等舱', '50', '150.00');
INSERT INTO `seat` VALUES ('MU5368', '商务舱', '30', '120.00');
INSERT INTO `seat` VALUES ('MU5368', '经济舱', '80', '100.00');
INSERT INTO `seat` VALUES ('MU5368', '头等舱', '50', '150.00');
INSERT INTO `seat` VALUES ('MU5331', '商务舱', '30', '800.00');
INSERT INTO `seat` VALUES ('MU5331', '经济舱', '75', '600.00');
INSERT INTO `seat` VALUES ('MU5331', '头等舱', '30', '1000.00');
INSERT INTO `seat` VALUES ('MU5332', '商务舱', '30', '800.00');
INSERT INTO `seat` VALUES ('MU5332', '经济舱', '75', '600.00');
INSERT INTO `seat` VALUES ('MU5332', '头等舱', '30', '1000.00');
INSERT INTO `seat` VALUES ('CZ3809', '商务舱', '25', '900.00');
INSERT INTO `seat` VALUES ('CZ3809', '经济舱', '90', '750.00');
INSERT INTO `seat` VALUES ('CZ3809', '头等舱', '40', '1080.00');
INSERT INTO `seat` VALUES ('CZ3810', '商务舱', '25', '900.00');
INSERT INTO `seat` VALUES ('CZ3810', '经济舱', '90', '750.00');
INSERT INTO `seat` VALUES ('CZ3810', '头等舱', '40', '1080.00');
INSERT INTO `seat` VALUES ('CA1893', '商务舱', '35', '1030.00');
INSERT INTO `seat` VALUES ('CA1893', '经济舱', '85', '900.00');
INSERT INTO `seat` VALUES ('CA1893', '头等舱', '30', '1180.00');
INSERT INTO `seat` VALUES ('CA1894', '商务舱', '35', '1030.00');
INSERT INTO `seat` VALUES ('CA1894', '经济舱', '85', '900.00');
INSERT INTO `seat` VALUES ('CA1894', '头等舱', '30', '1180.00');

-- ----------------------------
-- Table structure for `state`
-- ----------------------------
DROP TABLE IF EXISTS `state`;
CREATE TABLE `state` (
  `fs_number` varchar(20) DEFAULT NULL,
  `fs_date` varchar(10) NOT NULL,
  `fs_state` varchar(800) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of state
-- ----------------------------
INSERT INTO `state` VALUES ('CA1893', '2018-02-10', '延误了');

-- ----------------------------
-- Table structure for `tickets`
-- ----------------------------
DROP TABLE IF EXISTS `tickets`;
CREATE TABLE `tickets` (
  `t_id` varchar(100) NOT NULL,
  `t_f_number` varchar(30) DEFAULT NULL,
  `t_uid` varchar(20) DEFAULT NULL,
  `t_seatId` varchar(10) DEFAULT NULL,
  `t_type` varchar(20) DEFAULT NULL,
  `t_date` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`t_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tickets
-- ----------------------------
INSERT INTO `tickets` VALUES ('e1318', 'CA1893', 'malina', '1', '经济舱', '2018-02-15');
INSERT INTO `tickets` VALUES ('e4908790', 'MU5331', 'otcyan', '1', '头等舱', '2012-12-13');
INSERT INTO `tickets` VALUES ('e4908791', 'MU5331', 'otcyan', '14', '头等舱', '2012-12-13');
INSERT INTO `tickets` VALUES ('e9605', 'CA1893', 'llq', '1', '经济舱', '2018-02-06');

-- ----------------------------
-- Table structure for `users`
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users` (
  `U_ID` varchar(20) NOT NULL,
  `U_PASSWORD` varchar(20) NOT NULL,
  `U_NAME` varchar(20) NOT NULL,
  `U_SEX` varchar(2) DEFAULT NULL,
  `U_TELEPHONE` varchar(20) NOT NULL,
  `U_ADDRESS` varchar(100) NOT NULL,
  `U_EMAIL` varchar(20) NOT NULL,
  `U_IDCARD` varchar(20) DEFAULT NULL,
  `U_POWER` varchar(1) NOT NULL,
  PRIMARY KEY (`U_ID`),
  KEY `AK_Key_2` (`U_IDCARD`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of users
-- ----------------------------
INSERT INTO `users` VALUES ('admin', '1', 'otcyan', '男', '18073435677', '湖南衡阳', 'otcyan@qq.com', '430421199110083711', '1');
INSERT INTO `users` VALUES ('guowen', '121122', '秦国文', '男', '18073435677', '湖南衡阳', 'otcyan@qq.com', '430421199110083715', '0');
INSERT INTO `users` VALUES ('joychen', '121122', '刘程', '男', '18073435677', '湖南衡阳', 'otcyan@qq.com', '430421199110083718', '0');
INSERT INTO `users` VALUES ('llq', '123', '明礼馨德', '男', '13918621258', '上海', 'llq@qq.com', '622921199104052624', '0');
INSERT INTO `users` VALUES ('malina', '1', '马俐娜', '女', '18073435677', '湖南衡阳', 'otcyan@qq.com', '430421199110083713', '0');
INSERT INTO `users` VALUES ('otcyan', '121122', '欧阳健', '男', '18073435677', '湖南衡阳', 'otcyan@qq.com', '430421199110083710', '1');
INSERT INTO `users` VALUES ('tiantian', '121122', '薛勇军', '男', '18073435677', '湖南衡阳', 'otcyan@qq.com', '430421199110083712', '0');
INSERT INTO `users` VALUES ('xiaohua', '121122', '小狗', '男', '18073435677', '湖南衡阳', 'otcyan@qq.com', '430421199110083714', '0');
