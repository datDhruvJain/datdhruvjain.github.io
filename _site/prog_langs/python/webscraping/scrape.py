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
