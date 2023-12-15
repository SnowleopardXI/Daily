/*
 Navicat Premium Data Transfer

 Source Server         : 10.40.172.1_3306
 Source Server Type    : MariaDB
 Source Server Version : 100612
 Source Host           : 127.0.0.1:3306
 Source Schema         : UsageRecord

 Target Server Type    : MariaDB
 Target Server Version : 100612
 File Encoding         : 65001

 Date: 15/12/2023 00:53:12
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for Devices
-- ----------------------------
DROP TABLE IF EXISTS `Devices`;
CREATE TABLE `Devices`  (
  `DeviceID` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
  `Type` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
  `Location` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
  PRIMARY KEY (`DeviceID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 7 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of Devices
-- ----------------------------
INSERT INTO `Devices` VALUES (1, 'Cube', 'Exp', 'Lab');
INSERT INTO `Devices` VALUES (2, 'Laptop', 'PC', 'Lab');
INSERT INTO `Devices` VALUES (4, 'Microscope', 'Exp', 'Lab');
INSERT INTO `Devices` VALUES (5, 'bubuuu', 'bu', '114');
INSERT INTO `Devices` VALUES (6, 'bu', 'bu', 'han');

-- ----------------------------
-- Table structure for UsageRecords
-- ----------------------------
DROP TABLE IF EXISTS `UsageRecords`;
CREATE TABLE `UsageRecords`  (
  `RecordID` int(11) NOT NULL AUTO_INCREMENT,
  `DeviceID` int(11) NULL DEFAULT NULL,
  `UserID` int(11) NULL DEFAULT NULL,
  `StartTime` timestamp NULL DEFAULT NULL,
  `EndTime` timestamp NULL DEFAULT NULL,
  `Status` tinyint(2) NULL DEFAULT 0,
  PRIMARY KEY (`RecordID`) USING BTREE,
  INDEX `DeviceID`(`DeviceID`) USING BTREE,
  INDEX `UserID`(`UserID`) USING BTREE,
  CONSTRAINT `UsageRecords_ibfk_1` FOREIGN KEY (`DeviceID`) REFERENCES `Devices` (`DeviceID`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `UsageRecords_ibfk_2` FOREIGN KEY (`UserID`) REFERENCES `Users` (`UserID`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 16 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of UsageRecords
-- ----------------------------
INSERT INTO `UsageRecords` VALUES (3, 4, 0, '2023-11-15 01:06:16', '2023-11-17 01:07:10', 1);
INSERT INTO `UsageRecords` VALUES (7, 1, 1, '2023-11-18 00:00:00', '2023-11-18 03:26:17', 1);
INSERT INTO `UsageRecords` VALUES (8, 1, 1, '2023-11-18 00:05:04', '2023-11-18 03:27:57', 1);
INSERT INTO `UsageRecords` VALUES (10, 4, 1, '2023-11-18 04:11:12', '2023-12-15 00:50:56', 1);
INSERT INTO `UsageRecords` VALUES (11, 1, 1, '2023-11-18 04:07:24', '2023-11-18 12:44:36', 1);
INSERT INTO `UsageRecords` VALUES (12, 2, 1, '2023-11-18 03:19:09', '2023-11-18 18:28:30', 1);
INSERT INTO `UsageRecords` VALUES (13, 5, 1, '2023-11-18 21:13:28', '2023-12-15 00:04:39', 1);
INSERT INTO `UsageRecords` VALUES (14, 4, 1, '2023-12-15 00:16:36', '2023-12-15 00:50:56', 1);
INSERT INTO `UsageRecords` VALUES (15, 4, 1, '2023-12-15 00:46:16', '2023-12-15 00:50:56', 1);

-- ----------------------------
-- Table structure for Users
-- ----------------------------
DROP TABLE IF EXISTS `Users`;
CREATE TABLE `Users`  (
  `UserID` int(11) NOT NULL,
  `Type` tinyint(2) NOT NULL,
  `Name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
  `ContactInfo` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
  `Valid` tinyint(2) NOT NULL DEFAULT 1,
  `Password` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  PRIMARY KEY (`UserID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of Users
-- ----------------------------
INSERT INTO `Users` VALUES (0, 1, 'admin', 'admin@localhost', 1, '123456');
INSERT INTO `Users` VALUES (1, 0, 'test', 'test@test.com', 1, '123123');

-- ----------------------------
-- View structure for DeviceStatus
-- ----------------------------
DROP VIEW IF EXISTS `DeviceStatus`;
CREATE ALGORITHM = UNDEFINED SQL SECURITY DEFINER VIEW `DeviceStatus` AS select `d`.`DeviceID` AS `设备ID`,`d`.`Name` AS `设备名称`,`d`.`Type` AS `设备类型`,`d`.`Location` AS `设备地址`,count(`ur`.`DeviceID`) AS `租借次数`,case when `ur_latest`.`Status` = 1 or `ur_latest`.`DeviceID` is null then '可用' else '占用' end AS `设备状态` from ((`Devices` `d` left join `UsageRecords` `ur` on(`d`.`DeviceID` = `ur`.`DeviceID`)) left join (select `ur_inner`.`DeviceID` AS `DeviceID`,`ur_inner`.`Status` AS `Status` from (`UsageRecords` `ur_inner` join (select `UsageRecords`.`DeviceID` AS `DeviceID`,max(`UsageRecords`.`RecordID`) AS `LatestRecordID` from `UsageRecords` group by `UsageRecords`.`DeviceID`) `ur_max` on(`ur_inner`.`DeviceID` = `ur_max`.`DeviceID` and `ur_inner`.`RecordID` = `ur_max`.`LatestRecordID`))) `ur_latest` on(`d`.`DeviceID` = `ur_latest`.`DeviceID`)) group by `d`.`DeviceID`;

-- ----------------------------
-- View structure for UserRentalInterval
-- ----------------------------
DROP VIEW IF EXISTS `UserRentalInterval`;
CREATE ALGORITHM = UNDEFINED SQL SECURITY DEFINER VIEW `UserRentalInterval` AS select `ur`.`UserID` AS `用户ID`,`ur`.`DeviceID` AS `设备ID`,`d`.`Type` AS `设备类型`,`d`.`Location` AS `设备地点`,`ur`.`StartTime` AS `租借开始时间`,`ur`.`EndTime` AS `租借结束时间`,timediff(`ur`.`EndTime`,`ur`.`StartTime`) AS `租借时长`,case when `ur`.`Status` = 0 then '未归还' else '已归还' end AS `归还状态` from (`UsageRecords` `ur` join `Devices` `d` on(`ur`.`DeviceID` = `d`.`DeviceID`));

SET FOREIGN_KEY_CHECKS = 1;
