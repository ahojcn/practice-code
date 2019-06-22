import requests

def main():
    r = requests.get('http://api.komavideo.com/news/list')
    print(r.json())

if __name__ == "__main__":
    main()