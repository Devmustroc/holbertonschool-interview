#!/usr/bin/python3
import requests

def parse_titles(posts, word_list, count):
    for post in posts:
        title = post['data']['title'].lower()
        for word in word_list:
            word = word.lower()
            n = title.count(word)
            count[word] = count.get(word, 0) + n

def print_format(count):
    sorted_count = sorted(count.items(), key=lambda x: (-x[1], x[0]))
    for k, v in sorted_count:
        if v > 0:
            print(f"{k}: {v}")

def count_words(subreddit, word_list, count=None, after=""):
    if count is None:
        count = {}

    base_url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "MyBot"}
    params = {"after": after}

    response = requests.get(base_url, allow_redirects=False, headers=headers, params=params)

    if response.status_code > 300:
        return None

    data = response.json().get('data')
    after = data.get('after')
    posts = data.get('children')

    parse_titles(posts, word_list, count)

    if after:
        count_words(subreddit, word_list, count, after)
    else:
        print_format(count)

if __name__ == '__main__':
    import sys

    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        subreddit = sys.argv[1]
        keywords = sys.argv[2:]
        count_words(subreddit, keywords)
