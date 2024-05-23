import hashlib
import pickle
from tqdm import tqdm

def md5_hash(s):
    m = hashlib.md5()
    m.update(s.encode())
    return m.hexdigest()

# 创建树状索引字典
tree_index = {}
#从00-00-0000到99-12-31，以数字生成MD5哈希并将其添加到树状索引中
for year in tqdm(range(0, 100), desc="Processing years"):
    for month in range(1, 13):
        for day in range(1, 32):
            num_str = f"{year:02d}-{month:02d}-{day:02d}"
            hash_str = md5_hash(num_str)
            first_key = hash_str[:3]
            second_key = hash_str[3:6]

            if first_key not in tree_index:
                tree_index[first_key] = {}
            if second_key not in tree_index[first_key]:
                tree_index[first_key][second_key] = []

            tree_index[first_key][second_key].append({'number': num_str, 'md5': hash_str})
#从0000-00-00到2100-12-31，以数字生成MD5哈希并将其添加到树状索引中
for year in tqdm(range(0, 2101), desc="Processing years"):
    for month in range(1, 13):
        for day in range(1, 32):
            num_str = f"{year:04d}-{month:02d}-{day:02d}"
            hash_str = md5_hash(num_str)
            first_key = hash_str[:3]
            second_key = hash_str[3:6]

            if first_key not in tree_index:
                tree_index[first_key] = {}
            if second_key not in tree_index[first_key]:
                tree_index[first_key][second_key] = []

            tree_index[first_key][second_key].append({'number': num_str, 'md5': hash_str})

# 保存到二进制文件
with open('md5_tree_index.pkl', 'wb') as binary_file:
    pickle.dump(tree_index, binary_file)
