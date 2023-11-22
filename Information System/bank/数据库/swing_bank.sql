-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 22, 2023 at 12:11 AM
-- Server version: 10.6.12-MariaDB-0ubuntu0.22.04.1-log
-- PHP Version: 8.1.2-1ubuntu2.14

SET FOREIGN_KEY_CHECKS=0;
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `swing_bank`
--

DELIMITER $$
--
-- Procedures
--
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
(5, '1223334444', '123456', 70.00, 1),
(6, '123456789', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', 8.00, 1),
(10, '2021', '7c4a8d09ca3762af61e59520943dc26494f8941b', 10923536.00, 1),
(11, '2022', '6216f8a75fd5bb3d5f22b6f9958cdede3fc086c2', 888.00, 1),
(12, '2023', 'fd93ac461456a118d38a8d6b4d18f6741682f3eb', 234.00, 1),
(13, '123123', '40bd001563085fc35165329ea1ff5c5ecbdbbeef', 111.00, 1),
(14, '1919', '7c4a8d09ca3762af61e59520943dc26494f8941b', 1116499.00, 1),
(15, '20212554', 'fd93ac461456a118d38a8d6b4d18f6741682f3eb', 0.00, 1);

-- --------------------------------------------------------

--
-- Table structure for table `consumption`
--

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
(83, '取款', 111.00, '2023-11-04 23:26:46', 14),
(84, '转出:账号信息 1919', 1.00, '2023-11-12 22:52:31', 6),
(85, '转入:账号信息 123456789', 1.00, '2023-11-12 22:52:31', 14),
(86, '转出:账号信息 1919', 1.00, '2023-11-12 22:53:02', 6),
(87, '转入:账号信息 123456789', 1.00, '2023-11-12 22:53:02', 14),
(88, '转出:账号信息 1919', 1.00, '2023-11-12 22:55:05', 6),
(89, '转入:账号信息 123456789', 1.00, '2023-11-12 22:55:05', 14),
(90, '转出:账号信息 1919', 1.00, '2023-11-12 22:56:51', 6),
(91, '转入:账号信息 123456789', 1.00, '2023-11-12 22:56:51', 14),
(92, '转出:账号信息 1919', 1.00, '2023-11-12 22:58:33', 6),
(93, '转入:账号信息 123456789', 1.00, '2023-11-12 22:58:33', 14),
(94, '转出:账号信息 1919', 1.00, '2023-11-12 23:04:24', 6),
(95, '转入:账号信息 123456789', 1.00, '2023-11-12 23:04:24', 14),
(96, '转出:账号信息 1919', 1.00, '2023-11-12 23:04:40', 6),
(97, '转入:账号信息 123456789', 1.00, '2023-11-12 23:04:40', 14),
(98, '转出:账号信息 1919', 1.00, '2023-11-12 23:06:47', 6),
(99, '转入:账号信息 123456789', 1.00, '2023-11-12 23:06:47', 14),
(100, '转出:账号信息 1919', 1.00, '2023-11-12 23:06:58', 6),
(101, '转入:账号信息 123456789', 1.00, '2023-11-12 23:06:58', 14),
(102, '转出:账号信息 1919', 1.00, '2023-11-12 23:07:06', 6),
(103, '转入:账号信息 123456789', 1.00, '2023-11-12 23:07:06', 14),
(104, '转出:账号信息 1919', 1.00, '2023-11-12 23:12:37', 6),
(105, '转入:账号信息 123456789', 1.00, '2023-11-12 23:12:37', 14),
(106, '转出:账号信息 2021', 111.00, '2023-11-12 23:12:50', 6),
(107, '转入:账号信息 123456789', 111.00, '2023-11-12 23:12:50', 10),
(108, '存款', 11111.00, '2023-11-13 11:49:18', 14),
(109, '取款', 111.00, '2023-11-13 12:34:20', 14),
(110, '开户', 0.00, '2023-11-14 11:58:24', 15),
(111, '存款', 1.00, '2023-11-21 08:30:15', 14),
(112, '取款', 11111.00, '2023-11-21 08:32:34', 14),
(113, '取款', 111.00, '2023-11-21 08:38:46', 14),
(114, '转出:账号信息 2021', 1211.00, '2023-11-21 08:39:06', 14),
(115, '转入:账号信息 1919', 1211.00, '2023-11-21 08:39:06', 10),
(116, '转出:账号信息 2021', 111.00, '2023-11-21 08:40:07', 14),
(117, '转入:账号信息 1919', 111.00, '2023-11-21 08:40:07', 10),
(118, '取款', 1000.00, '2023-11-21 08:40:32', 14),
(119, '存款', 100000.00, '2023-11-21 08:44:12', 14),
(120, '取款', 58101.00, '2023-11-21 08:49:13', 14),
(121, '取款', 50000.00, '2023-11-21 10:00:22', 14),
(122, '存款', 1145.00, '2023-11-21 10:20:11', 14),
(123, '取款', 900.00, '2023-11-21 10:35:35', 5),
(124, '存款', 222222.00, '2023-11-21 10:58:23', 14),
(125, '取款', 111111.00, '2023-11-21 11:06:49', 14),
(126, '转出:账号信息 2021', 112000.00, '2023-11-21 11:13:56', 14),
(127, '转入:账号信息 1919', 112000.00, '2023-11-21 11:13:56', 10),
(128, '存款', 12222.00, '2023-11-21 11:14:20', 14),
(129, '存款', 22222.00, '2023-11-21 11:21:23', 14),
(130, '取款', 30000.00, '2023-11-21 11:22:20', 14),
(131, '存款', 100000.00, '2023-11-21 11:25:36', 14),
(132, '取款', 100.00, '2023-11-21 11:25:45', 14),
(133, '取款', 5000.00, '2023-11-21 11:26:16', 14),
(134, '取款', 50000.00, '2023-11-21 11:26:20', 14),
(135, '取款', 1111.00, '2023-11-21 23:23:11', 14),
(136, '取款', 11111.00, '2023-11-21 23:24:18', 14),
(137, '取款', 11111.00, '2023-11-21 23:30:43', 14),
(138, '存款', 12312341.00, '2023-11-21 23:31:00', 14),
(139, '存款', 22222222.00, '2023-11-21 23:31:52', 14),
(140, '取款', 11111111.00, '2023-11-21 23:31:59', 14),
(141, '取款', 11111111.00, '2023-11-21 23:33:45', 14),
(142, '取款', 11111111.00, '2023-11-21 23:47:16', 14),
(143, '取款', 1111111.00, '2023-11-21 23:47:25', 14),
(144, '取款', 111111.00, '2023-11-21 23:47:30', 14),
(145, '存款', 1111111.00, '2023-11-21 23:51:31', 14);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

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
(11, '是学生', '1111', '514', 14),
(12, 'test', 'n', '911', 15);

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
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `consumption`
--
ALTER TABLE `consumption`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=146;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

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
SET FOREIGN_KEY_CHECKS=1;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
