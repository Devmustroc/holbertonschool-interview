#!/usr/bin/python3
"""Task 0: Count it!"""

import requests


def parse_titles(posts, word_list, count):
    """Parses the titles of the posts and updates the count"""
    for post in posts:
        title = post.get('data').get('title').lower().split()
        for word in word_list:
            word = word.lower()
            n = title.count(word)
            count[word] = count.setdefault(word, 0) + n


def print_format(count):
    """
    Prints the count with the correct format
    """
    sorted_count = sorted(count.items(), key=lambda x: (-x[1], x[0]))

    for k, v in sorted_count:
        if v > 0:
            print("{}: {}".format(k, v))


def count_words(subreddit, word_list, count={}, after=""):
    """
    Queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords
    """
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-agent': 'MyBot'}
    params = {'after': after}

    result = requests.get(url,
                          allow_redirects=False,
                          headers=headers,
                          params=params)

    if result.status_code > 300:
        return None

    data = result.json().get('data')
    after = data.get('after')
    posts = data.get('children')

    parse_titles(posts, word_list, count)

    if after is not None:
        count_words(subreddit, word_list, count, after)
    else:
        print_format(count)
