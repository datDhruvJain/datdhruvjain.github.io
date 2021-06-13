import re

urls = '''
https://www.google.com
http://coreyms.com
https://youtube.com
http://www.nasa.gov
'''

patterns = re.compile(r"http[s]?://(www.)?(\w+)(\.\w+)")

'''matches = patterns.finditer(urls)

for match in matches:
    #print(match)
    #print(match.group(0)) # prints the whole match
    #print(match.group(1)) # prints the 1st group
    print(match.group(3)) # prints the 3rd group
'''
'''
# Substitutions
subbed_urls = patterns.sub(r"\2\3", urls)
print(subbed_urls)
# prints only the domain and high level domain
'''
# findall method, sends only the matched items
# print(re.compile(r"https?://www").findall(urls))

# re.compile(lala).match() -> only searches for matches at the begining

# re.compile().search -> checks for matches and returns location of the first match

# re.compile() takes a flag called re.IGNORECASE which matches irrespective of the case of the text_to_search 