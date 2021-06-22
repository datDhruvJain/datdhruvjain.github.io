# Web Scraping using Python

We are going to use the beautifulsoup4 library of python to scrape data.

used the link (https://coreyms.com/)

<details markdown=1>
<summary> Dependencies </summary>

- lxml (parser)
- html5lib (parser)
- requests (pata nahi bro kya hai yeh)
</details>

### creating a BeautifulSoup object

```python
soup = BeautifulSoup(file, parser)
```

the prettify method (`soup.prettier()`) adds indenting to the output

The code plus some explaination upto here
```python
from bs4 import BeautifulSoup
import requests

with open("simple.html","r") as html_file:
    soup = BeautifulSoup(html_file,"lxml")

# to have indents and stuff while outputing the html file
# print(soup.prettier())

# printing the tags only (here it's the title tag)
#print(soup.title)
# to get only the text of the tag:
#print(soup.title.text)

# finding stufff (ddiv in this case)
article = soup.find("div", class_="article")   # use "class_" only because class is a keword in python
# print(article)

# accessing a child tag
#headline = article.h2.a.text    # Here if we see, the headline is actually in the anchor tag
#print(headline)

#summary = article.p.text
#print(summary)

# the findall method - gives all instances
for article in soup.find_all("div", class_="article"):
    headline = article.h2.a.text
    print(headline)
    summary = article.p.text
    print(summary)
    print()
```
