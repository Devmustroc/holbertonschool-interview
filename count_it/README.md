# Count it!
****
## Resources
#### Read or watch:
* [Reddit API Documentation](https://www.reddit.com/dev/api/)

## Requirements
### General
* Allowed editors: <span style="color: red;">VI</span>  , <span style="color: red;">VIM</span>, <span style="color: red;">EMACS</span>
* All your files will be interpreted/compiled on Ubuntu 14.04 LTS using <span style="color: red;">PYTHON</span> (version 3.4.3)
* All your files should end with a new line
* The first line of all your files should be exactly <span style="color: red;">#!/usr/bin/python3</span>
* Libraries imported in your Python files must be organized in alphabetical order
* A <span style="color: red;">README.md</span> file, at the root of the folder of the project, is mandatory
* Your code should use the <span style="color: red;">PEP 8</span> style
* All your files must be executable
* The length of your files will be tested using <span style="color: red;">WC</span>
* All your modules should have a documentation (<span style="color: red;">python3 -c 'print(__import__("my_module").__doc__)'</span>)
* You must use the Requests module for sending HTTP requests to the Reddit API

### Tasks
#### 0.Count it!
Write a recursive function that queries the [Reddit API](https://www.reddit.com/dev/api/), parses the title of all hot articles, and prints a sorted count of given keywords (case-insensitive, delimited by spaces. <span style="color: green;">Javascript</span> should count as <span style="color: green;">Javascript</span>, but <span style="color: red;">Javascript</span> should not).

Requirements:

* Prototype: <span style="color: green;"><strong>def count_words(subreddit, word_list)</strong></span>
* Note: You may change the prototype, but it must be able to be called with just a subreddit supplied and a list of keywords. AKA you can add a counter or anything else, but the function must work without supplying a starting value in the main.
* If <span style="color: green;">word_list</span> contains the same word (case-insensitive), the final count should be the sum of each duplicate (example below with <span style="color: green;">java</span>)
* Results should be printed in descending order, by the count, and if the count is the same for separate keywords, they should then be sorted alphabetically (ascending, from A to Z). Words with no matches should be skipped and not printed. Words must be printed in lowercase.
* Results are based on the number of times a keyword appears, not titles it appears in. <span style="color: green;">java java java</span> counts as 3 separate occurrences of <span style="color: green">java</span>.
* To make life easier, <span>java.</span> or <span style="color: green;">java!</span> or java_ should not count as <span style="color: green;">java</span>
* If no posts match or the subreddit is invalid, print nothing.
* NOTE: Invalid subreddits may return a redirect to search results. Ensure that you are NOT following redirects.
Your code will NOT pass if you are using a loop and not recursively calling the function! This /can/ be done with a loop but the point is to use a recursive function. :)

<strong>Disclaimer:</strong> number presented in this example cannot be accurate now - Reddit is hot articles are always changing.

```
bob@dylan $ cat 0-main.py 
#!/usr/bin/python3
"""
0-main
"""
import sys

if __name__ == '__main__':
    count_words = __import__('0-count').count_words
    if len(sys.argv) < 3:
        print("Usage: {} <subreddit> <list of keywords>".format(sys.argv[0]))
        print("Ex: {} programming 'python java javascript'".format(sys.argv[0]))
    else:
        result = count_words(sys.argv[1], [x for x in sys.argv[2].split()])
bob@dylan $             
bob@dylan $ python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
java: 27
javascript: 20
python: 17
react: 17
scala: 4
bob@dylan $ python3 0-main.py programming 'JavA java'
java: 54
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
bob@dylan $ python3 0-main.py not_a_valid_subreddit 'python java'
bob@dylan $ 
```

