
library(ggplot2)  # for creating graphs
#library(dplyr)
#library(hrbrthemes)





#install.packages("hrbrthemes",repos = "http://cran.us.r-project.org")

filepath <- "Total_portfolio.txt"
df <- read.table(filepath, sep = ",",header = TRUE)

df$Time<-factor(df$Time, levels = df$Time)


p <- ggplot(data = df, mapping = aes(x = Time, y = Balance,group=1))+
  geom_line(color = "#00AFBB", linewidth = 2)+theme_bw()+
  theme(axis.text.x = element_text(angle=90))

print(p)
###ggplot(df, aes(x = Time, y = Balance)) + 
  #geom_line( color="#69b3a2") + 
 # xlab("") +
 # theme_ipsum() +
 # theme(axis.text.x=element_text(angle=60, hjust=1)) 
 
