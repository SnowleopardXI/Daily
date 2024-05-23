import hashlib
import pickle
from tqdm import tqdm

def md5_hash(s):
    m = hashlib.md5()
    m.update(s.encode())
    return m.hexdigest()

# 创建树状索引字典
tree_index = {}

# 使用tqdm显示进度条
for number in tqdm(range(1000000), desc="Processing numbers"):
    num_str = f"{number:06d}"
    hash_str = md5_hash(num_str)
    # 使用前三个字符作为第一级键，接下来三个字符作为第二级键
    first_key = hash_str[:3]
    second_key = hash_str[3:6]

    if first_key not in tree_index:
        tree_index[first_key] = {}
    if second_key not in tree_index[first_key]:
        tree_index[first_key][second_key] = []

    # 将完整的哈希和原始数字添加到相应的位置
    tree_index[first_key][second_key].append({'number': num_str, 'md5': hash_str})

# 从10000000到99999999，生成MD5哈希并将其添加到树状索引中
for number in tqdm(range(10000000, 100000000), desc="Processing numbers"):
    num_str = str(number)
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
