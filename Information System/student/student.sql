/*
Navicat MySQL Data Transfer

Source Server         : 毕业生管理系统
Source Server Version : 80021
Source Host           : localhost:3306
Source Database       : student

Target Server Type    : MYSQL
Target Server Version : 80021
File Encoding         : 65001

*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `stu`
-- ----------------------------
DROP TABLE IF EXISTS `stu`;
CREATE TABLE `stu` (
  `name` varchar(20) NOT NULL,
  `sex` varchar(20) NOT NULL,
  `age` varchar(20) NOT NULL,
  `grade` varchar(20) NOT NULL,
  `number` varchar(20) NOT NULL,
  PRIMARY KEY (`number`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of stu
-- ----------------------------
INSERT INTO `stu` VALUES ('小A', '男', '20', '1班', '1');
INSERT INTO `stu` VALUES ('小B', '女', '24', '2班', '10');
INSERT INTO `stu` VALUES ('小C', '女', '24', '1班', '2');
INSERT INTO `stu` VALUES ('小D', '男', '24', '1班', '3');
INSERT INTO `stu` VALUES ('小E', '女', '20', '2班', '4');
INSERT INTO `stu` VALUES ('小F', '男', '24', '1班', '5');
INSERT INTO `stu` VALUES ('小G', '女', '21', '2班', '6');
INSERT INTO `stu` VALUES ('小H', '女', '22', '2班', '7');
INSERT INTO `stu` VALUES ('小I', '女', '21', '2班', '8');
INSERT INTO `stu` VALUES ('小J', '女', '20', '1班', '9');

-- ----------------------------
-- Table structure for `user`
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `name` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL DEFAULT '0',
  `account` varchar(20) NOT NULL,
  `password` varchar(20) NOT NULL,
  `start` varchar(20) CHARACTER SET gb2312 COLLATE gb2312_chinese_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`account`)
) ENGINE=InnoDB DEFAULT CHARSET=gb2312;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('用户A', 'admin', 'admin', '0');
INSERT INTO `user` VALUES ('管理员', 'root', 'root', '1');
INSERT INTO `user` VALUES ('用户B', 'studeng', 'student', '0');
