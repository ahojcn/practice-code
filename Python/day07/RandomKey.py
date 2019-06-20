import random

def generate_key(code_len = 4):
    """
    生成指定长度的验证码
    :param code_len: 验证码的长度，默认 4
    :return: 由大小写英文字母和数字构成的随机验证码
    """
    lower_c = 'abcdefghijklmnopqrstuvwxyz'
    upper_c = lower_c.upper()
    number = '0123456789'

    all_c = number + upper_c + lower_c
    key = ''
    for _ in range(code_len):
        index = random.randint(0, len(all_c) - 1)
        key += all_c[index]
    return key

if __name__ == '__main__':
    code = generate_key()
    print(code)