import queue
import requests
from bs4 import BeautifulSoup

initial_page = "https://en.wikipedia.org/wiki/Main_Page"
wiki = "/wiki"

to_check_wikis = ["https://es.wikipedia.org/", "https://fr.wikipedia.org/",
                  "https://it.wikipedia.org/", "https://de.wikipedia.org/",
                  "https://pt.wikipedia.org/"]

max_visits = 5

url_queue = queue.Queue()
seen = set()

seen.add(initial_page)
url_queue.put(initial_page)

file = open("smallest_graph.txt", "a")

i = 0

while(True):
    if (url_queue.empty() or i > max_visits):
        break

    current_url = url_queue.get()
    graph_line = ""
    try:
        code = requests.get(current_url)
        graph_line += current_url
    except:
        print("url is down.")
        continue
    plain = code.text
    #print(plain)
    s = BeautifulSoup(plain, "html.parser")
    print("Getting links from " + current_url)
    for link in s.findAll('a'):
        try:
            url_title = str(link.get('title'))
        except UnicodeEncodeError:
            print("Some kind of error with unicode idek topkek")
            continue
        
        if (url_title == "None"): #no title, no storing
            continue
        
        try:
            print("Title: " + url_title)
        except UnicodeEncodeError:
            print("Some kind of error with unicode for printing idek topkek")
            
        cur_link = str(link.get('href'))
        if (cur_link[0:5] != "https"):
            real_link = "https://en.wikipedia.org" + cur_link
        else:
            if (cur_link[0:25] in to_check_wikis):
                real_link = cur_link
            else:
                continue
        print(real_link)
        if (real_link not in seen): #link not seen
            url_queue.put(real_link) #put it on queue
            seen.add(real_link) #and set     
        
        graph_line = graph_line + " " + real_link #if seen, don't re-add to
        #queue, but still connects to the current link

    file.write(graph_line + '\n')

    i += 1
    
file.close()
