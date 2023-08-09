#!/usr/bin/python3
"""Count the number of the Reddit API"""

import requests

def parse_titles(posts, word_list, counting):
    """Parse the titles of the posts"""
    for post in posts:
        title = post['data']['title'].lower()
        for word in word_list:
            word = word.lower()
            n = title.count(word)
            counting[word] = counting.get(word, 0) + n


def print_formatted(count):
    """Print the count in a formatted way"""
    if not count:
        return

    sorted_count = sorted(count.items(), key=lambda x: x[0])
    sorted_count = sorted(sorted_count, key=lambda x: x[1], reverse=True)

    for key, value in sorted_count:
        if value == 0:
            continue
        print(f"{key}: {value}")


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
        print_formatted(count)
