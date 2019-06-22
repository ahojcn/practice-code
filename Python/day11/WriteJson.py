"""
使用 json 模块将字典或列表以 JSON 格式保存到文件中
"""

import json

def main():
    mydict = {
        'name': 'ahojcn',
        'age': 18,
        'qq': 2076430492,
        'friends': ['Tim', 'Jack'],
        'cars': [
            {'brand': 'BYD', 'max_speed': 180},
            {'brand': 'BJ40', 'max_speed': 200}
        ]
    }

    try:
        with open('data.json', 'w', encoding='utf-8') as f:
            json.dump(mydict, f)
    except IOError as e:
        print(e)
    print("保存数据完成！")


if __name__ == '__main__':
    main()