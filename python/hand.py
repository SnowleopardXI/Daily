# coding: utf-8
from PIL import Image, ImageFont
 
from handright import Template, handwrite
import os
#从text.txt中读取文本，保存到text变量中
with open('text.txt', 'r', encoding='utf-8') as file:
    text = file.read()
 
template = Template(
    background=Image.new(mode="1", size=(1700, 1900), color=1),
    font=ImageFont.truetype("kai.ttf", size=60),
    line_spacing=65,
    fill=0,  # 字体“颜色”
    left_margin=0,
    top_margin=0,
    right_margin=0,
    bottom_margin=0,
    word_spacing=0.05,
    line_spacing_sigma=0.09,  # 行间距随机扰动
    font_size_sigma=0.2,  # 字体大小随机扰动
    word_spacing_sigma=0.4,  # 字间距随机扰动
    end_chars="，。",  # 防止特定字符因排版算法的自动换行而出现在行首
    perturb_x_sigma=0.08,  # 笔画横向偏移随机扰动
    perturb_y_sigma=0.08,  # 笔画纵向偏移随机扰动
    perturb_theta_sigma=0.05,  # 笔画旋转偏移随机扰动
)
images = handwrite(text, template)
for i, im in enumerate(images):
    assert isinstance(im, Image.Image)
    im.save(os.path.join("output", f"{i}.png"))