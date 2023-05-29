# coding: utf-8
from PIL import Image, ImageFont
 
from handright import Template, handwrite
import os
#从text.txt中读取文本，保存到text变量中
with open('text.txt', 'r', encoding='utf-8') as file:
    text = file.read()
 
template = Template(
    background=Image.new(mode="1", size=(2018, 2084), color=1),
    font=ImageFont.truetype("kai.ttf", size=60),
    line_spacing=120,
    fill=0,  # 字体“颜色”
    left_margin=0,
    top_margin=0,
    right_margin=0,
    bottom_margin=0,
    word_spacing=0.08,
    line_spacing_sigma=1,  # 行间距随机扰动
    font_size_sigma=2,  # 字体大小随机扰动
    word_spacing_sigma=1,  # 字间距随机扰动
    end_chars="，。",  # 防止特定字符因排版算法的自动换行而出现在行首
    perturb_x_sigma=1,  # 笔画横向偏移随机扰动
    perturb_y_sigma=1,  # 笔画纵向偏移随机扰动
    perturb_theta_sigma=0.07,  # 笔画旋转偏移随机扰动
)
images = handwrite(text, template)
for i, im in enumerate(images):
    assert isinstance(im, Image.Image)
    im.show()
    im.save(r"output.webp".format(i))