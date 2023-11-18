-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 18, 2023 at 08:14 PM
-- Server version: 10.6.12-MariaDB-0ubuntu0.22.04.1-log
-- PHP Version: 8.1.2-1ubuntu2.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `UsageRecord`
--

-- --------------------------------------------------------

--
-- Table structure for table `Devices`
--

CREATE TABLE `Devices` (
  `DeviceID` int(11) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Type` varchar(100) DEFAULT NULL,
  `Location` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `Devices`
--

INSERT INTO `Devices` (`DeviceID`, `Name`, `Type`, `Location`) VALUES
(1, 'Cube', 'Exp', 'Lab'),
(2, 'Laptop', 'PC', 'Lab'),
(4, 'Microscope', 'Exp', 'Lab');

-- --------------------------------------------------------

--
-- Stand-in structure for view `DeviceStatus`
-- (See below for the actual view)
--
CREATE TABLE `DeviceStatus` (
`设备ID` int(11)
,`设备名称` varchar(255)
,`设备类型` varchar(100)
,`设备地址` varchar(255)
,`设备状态` varchar(2)
);

-- --------------------------------------------------------

--
-- Table structure for table `UsageRecords`
--

CREATE TABLE `UsageRecords` (
  `RecordID` int(11) NOT NULL,
  `DeviceID` int(11) DEFAULT NULL,
  `UserID` int(11) DEFAULT NULL,
  `StartTime` timestamp NULL DEFAULT NULL,
  `EndTime` timestamp NULL DEFAULT NULL,
  `Status` tinyint(2) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `UsageRecords`
--

INSERT INTO `UsageRecords` (`RecordID`, `DeviceID`, `UserID`, `StartTime`, `EndTime`, `Status`) VALUES
(3, 4, 0, '2023-11-17 17:06:16', '2023-11-16 17:07:10', 1),
(7, 1, 1, '2023-11-17 19:26:17', '2023-11-17 16:00:00', 1),
(8, 1, 1, '2023-11-17 19:27:57', '2023-11-17 16:00:00', 1),
(10, 4, 1, '2023-11-18 00:56:25', '2023-11-17 16:00:00', 1),
(11, 1, 1, '2023-11-18 01:07:24', '2023-11-17 16:00:00', 1),
(12, 2, 1, '2023-11-18 02:59:09', '2023-11-17 16:00:00', 1);

-- --------------------------------------------------------

--
-- Table structure for table `Users`
--

CREATE TABLE `Users` (
  `UserID` int(11) NOT NULL,
  `Type` tinyint(2) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `ContactInfo` varchar(255) DEFAULT NULL,
  `Valid` tinyint(2) NOT NULL DEFAULT 1,
  `Password` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `Users`
--

INSERT INTO `Users` (`UserID`, `Type`, `Name`, `ContactInfo`, `Valid`, `Password`) VALUES
(0, 1, 'admin', 'admin@localhost', 1, '123456'),
(1, 0, 'test', 'test@test.com', 1, '123123');

-- --------------------------------------------------------

--
-- Structure for view `DeviceStatus`
--
DROP TABLE IF EXISTS `DeviceStatus`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `DeviceStatus`  AS SELECT `d`.`DeviceID` AS `设备ID`, `d`.`Name` AS `设备名称`, `d`.`Type` AS `设备类型`, `d`.`Location` AS `设备地址`, CASE WHEN `ur_latest`.`Status` = 1 OR `ur_latest`.`DeviceID` is null THEN '可用' ELSE '占用' END AS `设备状态` FROM (`Devices` `d` left join (select `ur`.`DeviceID` AS `DeviceID`,`ur`.`Status` AS `Status` from (`UsageRecords` `ur` join (select `UsageRecords`.`DeviceID` AS `DeviceID`,max(`UsageRecords`.`RecordID`) AS `LatestRecordID` from `UsageRecords` group by `UsageRecords`.`DeviceID`) `ur_max` on(`ur`.`DeviceID` = `ur_max`.`DeviceID` and `ur`.`RecordID` = `ur_max`.`LatestRecordID`))) `ur_latest` on(`d`.`DeviceID` = `ur_latest`.`DeviceID`)) ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Devices`
--
ALTER TABLE `Devices`
  ADD PRIMARY KEY (`DeviceID`);

--
-- Indexes for table `UsageRecords`
--
ALTER TABLE `UsageRecords`
  ADD PRIMARY KEY (`RecordID`),
  ADD KEY `DeviceID` (`DeviceID`),
  ADD KEY `UserID` (`UserID`);

--
-- Indexes for table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`UserID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `Devices`
--
ALTER TABLE `Devices`
  MODIFY `DeviceID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `UsageRecords`
--
ALTER TABLE `UsageRecords`
  MODIFY `RecordID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `UsageRecords`
--
ALTER TABLE `UsageRecords`
  ADD CONSTRAINT `UsageRecords_ibfk_1` FOREIGN KEY (`DeviceID`) REFERENCES `Devices` (`DeviceID`),
  ADD CONSTRAINT `UsageRecords_ibfk_2` FOREIGN KEY (`UserID`) REFERENCES `Users` (`UserID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
