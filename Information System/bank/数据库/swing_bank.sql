-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 12, 2023 at 10:10 PM
-- Server version: 10.6.12-MariaDB-0ubuntu0.22.04.1-log
-- PHP Version: 8.1.2-1ubuntu2.14
SET FOREIGN_KEY_CHECKS=0;

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `swing_bank`
--
CREATE DATABASE IF NOT EXISTS `swing_bank` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
USE `swing_bank`;

DELIMITER $$
--
-- Procedures
--
DROP PROCEDURE IF EXISTS `update_pass`$$
CREATE DEFINER=`root`@`localhost` PROCEDURE `update_pass` (IN `user_id` INT, IN `old_password` VARCHAR(255), IN `new_password` VARCHAR(255), OUT `result` INT)   BEGIN
    DECLARE db_password VARCHAR(255);
    
    -- Get the stored password for the provided id
    SELECT password INTO db_password FROM card WHERE id  = user_id;
    
    -- Check if the SHA1 of the provided old password matches the stored password
    IF db_password = sha1(old_password) THEN
        -- If they match, update the password to the SHA1 of the new password
        UPDATE card SET password = SHA1(new_password) WHERE id = user_id;
        SET result = 1;  -- Indicate success
    ELSE
        SET result = 0;  -- Indicate failure
    END IF;

END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `admins`
--

DROP TABLE IF EXISTS `admins`;
CREATE TABLE `admins` (
  `id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admins`
--

INSERT INTO `admins` (`id`, `name`, `password`) VALUES
(1, 'root', '123456');

-- --------------------------------------------------------

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
CREATE TABLE `card` (
  `id` int(11) NOT NULL,
  `cardname` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `price` decimal(10,2) NOT NULL,
  `valid` tinyint(4) NOT NULL DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

--
-- Dumping data for table `card`
--

INSERT INTO `card` (`id`, `cardname`, `password`, `price`, `valid`) VALUES
(5, '1223334444', '123456', 970.00, 1),
(6, '123456789', '7c4a8d09ca3762af61e59520943dc26494f8941b', 130.00, 1),
(10, '2021', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', 10810103.00, 1),
(11, '2022', '356a192b7913b04c54574d18c28d46e6395428ab', 888.00, 1),
(12, '2023', '6216f8a75fd5bb3d5f22b6f9958cdede3fc086c2', 234.00, 1),
(13, '123123', '6216f8a75fd5bb3d5f22b6f9958cdede3fc086c2', 111.00, 1),
(14, '1919', 'a1496d4ad0a359b6fe93d819e4a2141bd9d9ac35', 10746.00, 0);

-- --------------------------------------------------------

--
-- Table structure for table `consumption`
--

DROP TABLE IF EXISTS `consumption`;
CREATE TABLE `consumption` (
  `id` int(11) NOT NULL,
  `type` varchar(255) NOT NULL,
  `price` decimal(10,2) NOT NULL,
  `time` datetime NOT NULL DEFAULT current_timestamp(),
  `c_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

--
-- Dumping data for table `consumption`
--

INSERT INTO `consumption` (`id`, `type`, `price`, `time`, `c_id`) VALUES
(38, '开户', 0.00, '2023-11-03 17:00:17', 10),
(39, '存款', 1111111.00, '2023-11-03 17:01:08', 10),
(40, '开户', 0.00, '2023-11-03 17:13:47', 11),
(41, '取款', 99999.00, '2023-11-03 17:29:51', 10),
(42, '取款', 99999.00, '2023-11-03 17:29:54', 10),
(43, '取款', 99999.00, '2023-11-03 17:29:56', 10),
(44, '存款', 10000000.00, '2023-11-03 17:30:13', 10),
(45, '转出:账号信息 2022', 1234.00, '2023-11-03 17:30:29', 10),
(46, '转入:账号信息 2021', 1234.00, '2023-11-03 17:30:29', 11),
(47, '开户', 0.00, '2023-11-03 17:31:42', 12),
(48, '转出:账号信息 2023', 123.00, '2023-11-03 18:53:39', 11),
(49, '转入:账号信息 2022', 123.00, '2023-11-03 18:53:39', 12),
(50, '转出:账号信息 2021', 1.00, '2023-11-03 18:55:34', 11),
(51, '转入:账号信息 2022', 1.00, '2023-11-03 18:55:34', 10),
(52, '转出:账号信息 2021', 111.00, '2023-11-03 18:55:43', 11),
(53, '转入:账号信息 2022', 111.00, '2023-11-03 18:55:43', 10),
(54, '转出:账号信息 2021', 111.00, '2023-11-03 18:55:43', 11),
(55, '转入:账号信息 2022', 111.00, '2023-11-03 18:55:43', 10),
(56, '开户', 0.00, '2023-11-03 19:02:44', 13),
(57, '开户', 0.00, '2023-11-04 12:40:39', 14),
(58, '存款', 1000.00, '2023-11-04 17:16:34', 14),
(59, '转出:账号信息 2023', 111.00, '2023-11-04 17:38:39', 14),
(60, '转入:账号信息 1919', 111.00, '2023-11-04 17:38:39', 12),
(61, '取款', 1.00, '2023-11-04 19:48:39', 14),
(62, '取款', 1.00, '2023-11-04 19:48:45', 14),
(63, '存款', 1111.00, '2023-11-04 19:48:57', 14),
(64, '取款', 111.00, '2023-11-04 19:49:29', 14),
(65, '取款', 111.00, '2023-11-04 19:49:34', 14),
(66, '取款', 999.00, '2023-11-04 19:49:45', 14),
(67, '取款', 111.00, '2023-11-04 19:52:24', 14),
(68, '存款', 111111.00, '2023-11-04 19:52:40', 14),
(69, '取款', 111111.00, '2023-11-04 19:55:12', 14),
(70, '取款', 111.00, '2023-11-04 19:55:19', 14),
(71, '取款', 55.00, '2023-11-04 19:58:01', 14),
(72, '取款', 55.00, '2023-11-04 19:58:02', 14),
(73, '取款', 44.00, '2023-11-04 19:59:06', 14),
(74, '取款', 44.00, '2023-11-04 19:59:11', 14),
(75, '取款', 44.00, '2023-11-04 19:59:19', 14),
(76, '存款', 11111.00, '2023-11-04 20:10:48', 14),
(77, '取款', 111.00, '2023-11-04 20:10:52', 14),
(78, '取款', 123.00, '2023-11-04 20:15:02', 14),
(79, '取款', 111.00, '2023-11-04 20:29:27', 14),
(80, '取款', 111.00, '2023-11-04 20:39:34', 14),
(81, '转出:账号信息 123123', 111.00, '2023-11-04 20:44:12', 14),
(82, '转入:账号信息 1919', 111.00, '2023-11-04 20:44:12', 13),
(83, '取款', 111.00, '2023-11-04 23:26:46', 14);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `sex` varchar(255) NOT NULL,
  `telephone` varchar(255) NOT NULL,
  `c_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3 COLLATE=utf8mb3_general_ci;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id`, `username`, `sex`, `telephone`, `c_id`) VALUES
(3, 'admin', '男', '14525635896', 5),
(4, 'test', '男', '14574587458', 6),
(7, 'test', 'nb', '911', 10),
(8, 'test', 'n', '911', 11),
(9, 'awedawdaw', 'eaew', '911', 12),
(10, 'rrr', 'nb', '911', 13),
(11, '24', '111', '514', 14);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admins`
--
ALTER TABLE `admins`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `card`
--
ALTER TABLE `card`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `consumption`
--
ALTER TABLE `consumption`
  ADD PRIMARY KEY (`id`),
  ADD KEY `c_id` (`c_id`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk_id` (`c_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `card`
--
ALTER TABLE `card`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `consumption`
--
ALTER TABLE `consumption`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=84;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `consumption`
--
ALTER TABLE `consumption`
  ADD CONSTRAINT `fk_cc` FOREIGN KEY (`c_id`) REFERENCES `card` (`id`);

--
-- Constraints for table `user`
--
ALTER TABLE `user`
  ADD CONSTRAINT `fk_id` FOREIGN KEY (`c_id`) REFERENCES `card` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

SET FOREIGN_KEY_CHECKS=1;