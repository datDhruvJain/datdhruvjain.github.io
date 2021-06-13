from bs4 import BeautifulSoup
import requests
import csv
csv_file = open("scraped_csv.csv", 'w')

csv_writer = csv.writer(csv_file)
csv_writer.writerow(["Headline","Summary","Video Link"])
# specify the site
source = requests.get("http://coreyms.com").text    # the get method will return a response object, to get source code, add .text

soup = BeautifulSoup(source, "lxml")

# soup is the entire web page
# article is just a component of the soup, one portion/part of it.

articles = soup.find_all('article')
for article in articles:

    headline = article.h2.a.text
    #print(headline,"\n")

    para = article.find("div", class_="entry-content").p.text
    #print(para,'\n')

    try:
        # attributes of tags are accessed as in a dictionary as follows
        video_source = article.find('iframe', class_="youtube-player")['src']
        #print(video_source)

        vid_id = video_source.split('/')[4].split('?')[0]
        #print(vid_id)

        yt_link = f'https://youtube.com/watch?v={vid_id}'
    except Exception as e:
        yt_link = None
    #print(yt_link)
    
    csv_writer.writerow([headline, para, yt_link])

csv_file.close()    
