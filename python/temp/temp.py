import numpy as np
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties

# 设置中文字体
font = FontProperties(fname=r"c:\windows\fonts\simsun.ttc", size=12)
plt.rcParams["font.family"] = font.get_name()

# 数据
x = [0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5]
y1 = [0.0, 0.032, 0.048, 0.059, 0.084, 0.095, 0.102, 0.114, 0.124, 0.139, 0.154, 0.187]
y2 = [0.0, 0.021, 0.026, 0.032, 0.054, 0.066, 0.072, 0.084, 0.092, 0.102, 0.112, 0.187]

# 合并数据
x_combined = np.concatenate((x, x))
y_combined = np.concatenate((y1, y2))

# 用一次函数进行拟合
coefficients = np.polyfit(x_combined, y_combined, 1)
polynomial = np.poly1d(coefficients)

# 计算迟滞误差
hysteresis_error_y1 = y1 - polynomial(x)
hysteresis_error_y2 = y2 - polynomial(x)

# 绘图
plt.figure(figsize=(10,6))
plt.plot(x, y1, 'o-', label='y1 (递增电压)')
plt.plot(x, y2, 's-', label='y2 (递减电压)')
plt.plot(x, polynomial(x), 'r--', label='拟合线')
plt.fill_between(x, y1, y2, color='gray', alpha=0.2, label='迟滞误差')
plt.xlabel('位移 (单位: 毫米)')
plt.ylabel('输出电压 (单位: 伏特)')
plt.title('半桥电路输出电压与位移关系及迟滞误差')
plt.legend()
plt.grid(True)
plt.show()
import numpy as np
sensitivity = coefficients[0]
print("系统灵敏度（斜率）是:", sensitivity)