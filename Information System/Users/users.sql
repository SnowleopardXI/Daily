/*
 Navicat MySQL Data Transfer

 Source Server         : 678949
 Source Server Type    : MySQL
 Source Server Version : 80028 (8.0.28)
 Source Host           : localhost:3306
 Source Schema         : users

 Target Server Type    : MySQL
 Target Server Version : 80028 (8.0.28)
 File Encoding         : 65001

 Date: 17/11/2023 20:18:42
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for admin_login_k
-- ----------------------------
DROP TABLE IF EXISTS `admin_login_k`;
CREATE TABLE `admin_login_k`  (
  `admin_id` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `admin_name` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `admin_pass` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`admin_id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of admin_login_k
-- ----------------------------
INSERT INTO `admin_login_k` VALUES ('1', 'admin', '123456');

-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users`  (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `gender` varchar(4) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `age` tinyint NULL DEFAULT NULL,
  `phone` varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 9 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of users
-- ----------------------------
INSERT INTO `users` VALUES (5, 'guoye', '男', 18, '123456');
INSERT INTO `users` VALUES (6, '郭晔', '男', 21, '123');
INSERT INTO `users` VALUES (8, 'da', '男', 25, '52');

-- ----------------------------
-- Table structure for notes
-- ----------------------------
DROP TABLE IF EXISTS `notes`;
CREATE TABLE `notes`  (
  `id` int NULL DEFAULT NULL,
  `notes` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  INDEX `fk_id`(`id` ASC) USING BTREE,
  CONSTRAINT `fk_id` FOREIGN KEY (`id`) REFERENCES `users` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of notes
-- ----------------------------
INSERT INTO `notes` VALUES (5, '5555');

-- ----------------------------
-- View structure for notesview
-- ----------------------------
DROP VIEW IF EXISTS `notesview`;
CREATE ALGORITHM = UNDEFINED SQL SECURITY DEFINER VIEW `notesview` AS select `u`.`id` AS `ID`,`u`.`name` AS `姓名`,`u`.`gender` AS `性别`,`u`.`age` AS `年龄`,`n`.`notes` AS `备注` from (`users` `u` join `notes` `n` on((`u`.`id` = `n`.`id`)));

SET FOREIGN_KEY_CHECKS = 1;
