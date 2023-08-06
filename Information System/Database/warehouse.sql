SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for admin_actions
-- ----------------------------
DROP TABLE IF EXISTS `admin_actions`;
CREATE TABLE `admin_actions`  (
  `Action_ID` int NOT NULL AUTO_INCREMENT,
  `Admin_ID` int NULL DEFAULT NULL,
  `Action_Type` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `Action_Description` text CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL,
  `Action_Time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`Action_ID`) USING BTREE,
  INDEX `Admin_ID`(`Admin_ID`) USING BTREE,
  CONSTRAINT `Admin_Actions_ibfk_1` FOREIGN KEY (`Admin_ID`) REFERENCES `admins` (`Admin_ID`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 9 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for admins
-- ----------------------------
DROP TABLE IF EXISTS `admins`;
CREATE TABLE `admins`  (
  `Admin_ID` int NOT NULL AUTO_INCREMENT,
  `Admin_Name` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `Password` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `Admin_Type` int NULL DEFAULT NULL,
  `Email` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `Phone` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`Admin_ID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for inventory
-- ----------------------------
DROP TABLE IF EXISTS `inventory`;
CREATE TABLE `inventory`  (
  `Inventory_ID` int NOT NULL AUTO_INCREMENT,
  `Product_Name` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `Quantity` int NULL DEFAULT NULL,
  `Supplier_ID` int NULL DEFAULT NULL,
  `Warehouse_ID` int NULL DEFAULT NULL,
  `Action_ID` int NULL DEFAULT NULL,
  PRIMARY KEY (`Inventory_ID`) USING BTREE,
  INDEX `Supplier_ID`(`Supplier_ID`) USING BTREE,
  INDEX `Warehouse_ID`(`Warehouse_ID`) USING BTREE,
  CONSTRAINT `Inventory_ibfk_1` FOREIGN KEY (`Supplier_ID`) REFERENCES `suppliers` (`Supplier_ID`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `Inventory_ibfk_2` FOREIGN KEY (`Warehouse_ID`) REFERENCES `warehouses` (`Warehouse_ID`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 4 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for stock_records
-- ----------------------------
DROP TABLE IF EXISTS `stock_records`;
CREATE TABLE `stock_records`  (
  `Record_ID` int NOT NULL AUTO_INCREMENT,
  `Inventory_ID` int NULL DEFAULT NULL,
  `Quantity_Change` int NULL DEFAULT NULL,
  `Record_Time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `Admin_ID` int NULL DEFAULT NULL,
  PRIMARY KEY (`Record_ID`) USING BTREE,
  INDEX `Inventory_ID`(`Inventory_ID`) USING BTREE,
  INDEX `Admin_ID`(`Admin_ID`) USING BTREE,
  CONSTRAINT `Stock_Records_ibfk_1` FOREIGN KEY (`Inventory_ID`) REFERENCES `inventory` (`Inventory_ID`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `Stock_Records_ibfk_2` FOREIGN KEY (`Admin_ID`) REFERENCES `admins` (`Admin_ID`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `Stock_Records_ibfk_3` FOREIGN KEY (`Record_ID`) REFERENCES `admin_actions` (`Action_ID`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB AUTO_INCREMENT = 8 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for suppliers
-- ----------------------------
DROP TABLE IF EXISTS `suppliers`;
CREATE TABLE `suppliers`  (
  `Supplier_ID` int NOT NULL AUTO_INCREMENT,
  `Supplier_Name` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `Contact_Info` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `Address` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`Supplier_ID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 7 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for warehouses
-- ----------------------------
DROP TABLE IF EXISTS `warehouses`;
CREATE TABLE `warehouses`  (
  `Warehouse_ID` int NOT NULL AUTO_INCREMENT,
  `Warehouse_Location` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `Warehouse_Name` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `Warehouse_Contact` varchar(100) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`Warehouse_ID`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Procedure structure for Add_Inventory
-- ----------------------------
DROP PROCEDURE IF EXISTS `Add_Inventory`;
delimiter ;;
CREATE PROCEDURE `Add_Inventory`(IN p_Product_Name VARCHAR(100), 
    IN p_Supplier_Name VARCHAR(100), 
    IN p_Warehouse_ID INT, 
    IN p_Quantity INT, 
    IN p_Admin_ID INT)
BEGIN
    DECLARE p_Supplier_ID INT;
    DECLARE p_Inventory_ID INT;
    DECLARE p_Action_ID INT;

    -- 根据供应商名获取供应商ID
    SELECT Supplier_ID INTO p_Supplier_ID FROM Suppliers WHERE Supplier_Name = p_Supplier_Name;
  
    -- 检查该商品是否已经存在于库存中
    SELECT Inventory_ID INTO p_Inventory_ID FROM Inventory WHERE Product_Name = p_Product_Name AND Warehouse_ID = p_Warehouse_ID;

    -- 如果商品不存在，添加新的库存信息
    IF p_Inventory_ID IS NULL THEN
        INSERT INTO Inventory(Product_Name, Quantity, Supplier_ID, Warehouse_ID) 
        VALUES (p_Product_Name, p_Quantity, p_Supplier_ID, p_Warehouse_ID);

        SET p_Inventory_ID = LAST_INSERT_ID();
    ELSE
        -- 如果商品已经存在，更新库存数量
        UPDATE Inventory SET Quantity = Quantity + p_Quantity WHERE Inventory_ID = p_Inventory_ID;
    END IF;

    -- 记录管理员操作，并获取操作ID
    INSERT INTO Admin_Actions(Admin_ID, Action_Type, Action_Description, Action_Time) 
    VALUES (p_Admin_ID, '入库', CONCAT(' 仓库ID:', p_Warehouse_ID, '商品名称:', p_Product_Name, ' 供应商:', p_Supplier_Name, ' 数量:', p_Quantity), NOW());

    SET p_Action_ID = LAST_INSERT_ID();

    -- 记录库存变更，使用操作ID作为记录ID
    INSERT INTO Stock_Records(Record_ID, Inventory_ID, Quantity_Change, Record_Time, Admin_ID) 
    VALUES (p_Action_ID, p_Inventory_ID, p_Quantity, NOW(), p_Admin_ID);
  
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for Add_Suppliers
-- ----------------------------
DROP PROCEDURE IF EXISTS `Add_Suppliers`;
delimiter ;;
CREATE PROCEDURE `Add_Suppliers`(IN p_Supplier_Name VARCHAR(100),
    IN p_Contact_Info VARCHAR(100),
    IN p_Address VARCHAR(255),
    IN p_Admin_ID INT)
BEGIN
    DECLARE p_Supplier_ID INT;

    -- 检查该供应商名是否已存在
    SELECT Supplier_ID INTO p_Supplier_ID FROM Suppliers WHERE Supplier_Name = p_Supplier_Name;

    -- 如果该供应商名已存在，抛出错误
    IF p_Supplier_ID IS NOT NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '供应商已存在';
    ELSE
        -- 如果供应商名不存在，添加新的供应商信息
        INSERT INTO Suppliers(Supplier_Name, Contact_Info, Address) 
        VALUES (p_Supplier_Name, p_Contact_Info, p_Address);

        SET p_Supplier_ID = LAST_INSERT_ID();

        -- 添加管理员操作记录
        INSERT INTO Admin_Actions(Admin_ID, Action_Type, Action_Description, Action_Time) 
        VALUES (p_Admin_ID, '添加供应商', CONCAT('新增供应商名称: ', p_Supplier_Name, ', 联系方式: ', p_Contact_Info, ', 地址: ', p_Address), NOW());
    END IF;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for Add_Warehouse
-- ----------------------------
DROP PROCEDURE IF EXISTS `Add_Warehouse`;
delimiter ;;
CREATE PROCEDURE `Add_Warehouse`(IN p_Warehouse_Name VARCHAR(255),
    IN p_Warehouse_Location VARCHAR(255),
    IN p_Warehouse_Contact VARCHAR(100),
    IN p_Admin_ID INT)
BEGIN
    DECLARE existing_name INT;
    
    SELECT COUNT(*) INTO existing_name FROM Warehouses WHERE Warehouse_Name = p_Warehouse_Name;
    
    IF existing_name = 0 THEN
        INSERT INTO Warehouses(Warehouse_Name, Warehouse_Location, Warehouse_Contact) 
        VALUES (p_Warehouse_Name, p_Warehouse_Location, p_Warehouse_Contact);
        
        INSERT INTO Admin_Actions(Admin_ID, Action_Type, Action_Description, Action_Time) 
        VALUES (p_Admin_ID, '添加仓库', CONCAT('添加仓库: ', p_Warehouse_Name), NOW());
    ELSE
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '仓库已存在';
    END IF;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for Delete_Supplier
-- ----------------------------
DROP PROCEDURE IF EXISTS `Delete_Supplier`;
delimiter ;;
CREATE PROCEDURE `Delete_Supplier`(IN p_Supplier_ID INT,
    IN p_Admin_ID INT)
BEGIN
    DECLARE v_Supplier_Exists INT;
    DECLARE v_Product_Exists INT;
    DECLARE v_Supplier_Name VARCHAR(100);

    -- 检查供应商是否存在
    SELECT COUNT(*) INTO v_Supplier_Exists FROM Suppliers WHERE Supplier_ID = p_Supplier_ID;
    IF v_Supplier_Exists = 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '供应商不存在';
    ELSE
        -- 检查该供应商是否有相关的货物存在
        SELECT COUNT(*) INTO v_Product_Exists FROM Inventory WHERE Supplier_ID = p_Supplier_ID;
        IF v_Product_Exists > 0 THEN
            SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '供应商货物尚未清空';
        ELSE
            -- 获取供应商名称
            SELECT Supplier_Name INTO v_Supplier_Name FROM Suppliers WHERE Supplier_ID = p_Supplier_ID;
            
            -- 删除供应商信息
            DELETE FROM Suppliers WHERE Supplier_ID = p_Supplier_ID;
            
            -- 记录管理员操作
            INSERT INTO Admin_Actions(Admin_ID, Action_Type, Action_Description, Action_Time)
            VALUES (p_Admin_ID, '删除供应商', CONCAT('删除的供应商名称： ', v_Supplier_Name), NOW());
        END IF;
    END IF;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for Delete_Warehouse
-- ----------------------------
DROP PROCEDURE IF EXISTS `Delete_Warehouse`;
delimiter ;;
CREATE PROCEDURE `Delete_Warehouse`(
    IN p_Warehouse_ID INT,
    IN p_Admin_ID INT
)
BEGIN
    DECLARE warehouse_count INT;
    DECLARE inventory_count INT;
    DECLARE warehouse_name VARCHAR(255);

    -- 检查仓库是否存在
    SELECT COUNT(*), Warehouse_Name INTO warehouse_count, warehouse_name FROM Warehouses WHERE Warehouse_ID = p_Warehouse_ID;

    IF warehouse_count = 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '仓库不存在';
    ELSE
        -- 检查该仓库是否还有库存
        SELECT COUNT(*) INTO inventory_count FROM Inventory WHERE Warehouse_ID = p_Warehouse_ID;

        IF inventory_count > 0 THEN
            SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '仓库中还有库存，无法删除';
        ELSE
            DELETE FROM Warehouses WHERE Warehouse_ID = p_Warehouse_ID;

            INSERT INTO Admin_Actions(Admin_ID, Action_Type, Action_Description, Action_Time) 
            VALUES (p_Admin_ID, '删除仓库', CONCAT('删除仓库: ', warehouse_name), NOW());
        END IF;
    END IF;
END;;
delimiter ;

-- ----------------------------
-- Procedure structure for Remove_Inventory
-- ----------------------------
DROP PROCEDURE IF EXISTS `Remove_Inventory`;
delimiter ;;
CREATE PROCEDURE `Remove_Inventory`(IN p_Admin_ID INT,
    IN p_Product_Name VARCHAR(100),
    IN p_Quantity INT,
    IN p_Warehouse_ID INT,
    IN p_Status INT)
BEGIN
    DECLARE p_Inventory_ID INT;
    DECLARE p_Action_ID INT;
    DECLARE p_Quantity_Left INT;
    
    -- 从库存信息表中获取库存ID
    SELECT Inventory_ID INTO p_Inventory_ID FROM Inventory WHERE Product_Name = p_Product_Name AND Warehouse_ID = p_Warehouse_ID;

    IF p_Inventory_ID IS NULL THEN
        -- 如果没有找到匹配的库存信息，抛出错误
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '商品不存在';
    ELSE
        -- 检查剩余库存数量
        SELECT Quantity INTO p_Quantity_Left FROM Inventory WHERE Inventory_ID = p_Inventory_ID;
        
        -- 如果库存数量为0或者小于出库数量，抛出错误
        IF p_Quantity_Left = 0 OR p_Quantity_Left < p_Quantity THEN
            SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '商品库存不足';
        ELSE
            IF p_Status = 1 THEN
                -- 减少库存数量
                UPDATE Inventory SET Quantity = Quantity - p_Quantity WHERE Inventory_ID = p_Inventory_ID;
            
                -- 添加管理员操作记录，并获取操作ID
                INSERT INTO Admin_Actions(Admin_ID, Action_Type, Action_Description, Action_Time) 
                VALUES (p_Admin_ID, '出库', CONCAT(' 仓库ID:', p_Warehouse_ID,'商品名称:', p_Product_Name, ' 数量:', p_Quantity), NOW());

                SET p_Action_ID = LAST_INSERT_ID();

                -- 添加库存记录，使用操作ID作为记录ID
                INSERT INTO Stock_Records(Record_ID, Inventory_ID, Quantity_Change, Record_Time, Admin_ID) 
                VALUES (p_Action_ID, p_Inventory_ID, -p_Quantity, NOW(), p_Admin_ID);

                -- 检查剩余库存数量
                SELECT Quantity INTO p_Quantity_Left FROM Inventory WHERE Inventory_ID = p_Inventory_ID;

                -- 如果库存数量为0，记录管理员操作
                IF p_Quantity_Left = 0 THEN
                    INSERT INTO Admin_Actions(Admin_ID, Action_Type, Action_Description, Action_Time) 
                    VALUES (p_Admin_ID, '库存警告', CONCAT('仓库ID:', p_Warehouse_ID,'商品名称:', p_Product_Name, ' 库存已为空'), NOW());
                END IF;
            END IF;
        END IF;
    END IF;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for Update_Supplier
-- ----------------------------
DROP PROCEDURE IF EXISTS `Update_Supplier`;
delimiter ;;
CREATE PROCEDURE `Update_Supplier`(IN p_Supplier_ID INT,
    IN p_Supplier_Name VARCHAR(100),
    IN p_Contact_Info VARCHAR(100),
    IN p_Address VARCHAR(255),
    IN p_Admin_ID INT)
BEGIN
    DECLARE v_Supplier_Exists INT;
    DECLARE v_Supplier_Name_Exists INT;

    -- 检查供应商是否存在
    SELECT COUNT(*) INTO v_Supplier_Exists FROM Suppliers WHERE Supplier_ID = p_Supplier_ID;
    IF v_Supplier_Exists = 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '供应商不存在';
    ELSE
        -- 检查新名称是否与现有的供应商冲突
        SELECT COUNT(*) INTO v_Supplier_Name_Exists FROM Suppliers WHERE Supplier_Name = p_Supplier_Name AND Supplier_ID <> p_Supplier_ID;
        IF v_Supplier_Name_Exists > 0 THEN
            SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '供应商名称冲突';
        ELSE
            -- 更新供应商信息
            UPDATE Suppliers SET Supplier_Name = p_Supplier_Name, Contact_Info = p_Contact_Info, Address = p_Address WHERE Supplier_ID = p_Supplier_ID;
            
            -- 记录管理员操作
            INSERT INTO Admin_Actions(Admin_ID, Action_Type, Action_Description, Action_Time)
            VALUES (p_Admin_ID, '更新供应商', CONCAT('更新的供应商名称: ', p_Supplier_Name), NOW());
        END IF;
    END IF;
END
;;
delimiter ;

-- ----------------------------
-- Procedure structure for Update_Warehouse
-- ----------------------------
DROP PROCEDURE IF EXISTS `Update_Warehouse`;
delimiter ;;
CREATE PROCEDURE `Update_Warehouse`(IN p_Warehouse_ID INT,
    IN p_Warehouse_Name VARCHAR(255),
    IN p_Warehouse_Location VARCHAR(255),
    IN p_Warehouse_Contact VARCHAR(100),
    IN p_Admin_ID INT)
BEGIN
    DECLARE existing_name INT;
    
    SELECT COUNT(*) INTO existing_name FROM Warehouses WHERE Warehouse_Name = p_Warehouse_Name AND Warehouse_ID != p_Warehouse_ID;
    
    IF existing_name = 0 THEN
        UPDATE Warehouses
        SET Warehouse_Name = p_Warehouse_Name, Warehouse_Location = p_Warehouse_Location, Warehouse_Contact = p_Warehouse_Contact
        WHERE Warehouse_ID = p_Warehouse_ID;
        
        INSERT INTO Admin_Actions(Admin_ID, Action_Type, Action_Description, Action_Time) 
        VALUES (p_Admin_ID, '修改仓库', CONCAT('修改仓库ID: ', p_Warehouse_ID), NOW());
    ELSE
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = '仓库已存在';
    END IF;
END
;;
delimiter ;

SET FOREIGN_KEY_CHECKS = 1;
