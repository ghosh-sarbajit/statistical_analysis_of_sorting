heapbuild_data = read.csv(file.choose(),sep = ",",header = F)
heapbuild_data <- as.matrix(heapsort_data)
Min1 <- apply(heapbuild_data, 1, min)
Max1 <- apply(heapbuild_data, 1, max)
Mean1 <- apply(heapbuild_data, 1, mean)
x_val <- 100*(1:10)


heapsort_data = read.csv(file.choose(),sep = ",",header = F)
heapsort_data <- as.matrix(heapsort_data)
# edit(heapsort_data)
# head(heapsort_data)

Min <- apply(heapsort_data, 1, min)
Max <- apply(heapsort_data, 1, max)
Mean <- apply(heapsort_data, 1, mean)


par(mfrow = c(1,2))

plot(x_val,Max1,type = "b",col = "red",xlab = "ArrSize",ylab = "Num Of swaps")
points(x_val,Mean1,col = "blue",type = "b")
points(x_val,Min1,col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.8)

plot(x_val,Max1/(x_val),type = "b",col = "red",ylim = c(0.5,2.0),xlab = "ArrSize",ylab = "Num of swaps/(ArrSize)")
points(x_val,Mean1/(x_val),col = "blue",type = "b")
points(x_val,Min1/(x_val),col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.8)


plot(x_val,Max,type = "b",col = "red",xlab = "ArrSize",ylab = "Num Of swaps")
points(x_val,Mean,col = "blue",type = "b")
points(x_val,Min,col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.8)

plot(x_val,Max/(x_val * log(x_val,base = 2)),type = "b",col = "red",ylim = c(0.70,1.0),xlab = "ArrSize",ylab = "Num of swaps/(ArrSize * log(ArrSize))")
points(x_val,Mean/(x_val * log(x_val,base = 2)),col = "blue",type = "b")
points(x_val,Min/(x_val * log(x_val,base = 2)),col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.8)


