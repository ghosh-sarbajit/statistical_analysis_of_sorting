data1 = read.csv(file.choose(),sep = ",",header = F)
data1 <- as.matrix(data1)
# edit(data1)
# head(data1)
Min <- apply(data1, 1, min)
Max <- apply(data1, 1, max)
Mean <- apply(data1, 1, mean)
x_val <- 100*(1:10)
par(mfrow = c(1,2))

plot(x_val,Max,type = "b",col = "red",xlab = "ArraySize",ylab = "Num Of Shifts")
points(x_val,Mean,col = "blue",type = "b")
points(x_val,Min,col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.8)

plot(x_val,Max/(x_val^2),type = "b",col = "red",ylim = c(0.18,0.32),xlab = "ArraySize",ylab = "Num of shifts/(ArraySize^2)")
points(x_val,Mean/(x_val^2),col = "blue",type = "b")
points(x_val,Min/(x_val^2),col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.8)

?plot
