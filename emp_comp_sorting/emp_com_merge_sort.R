mergesort_data = read.csv(file.choose(),sep = ",",header = F)
mergesort_data <- as.matrix(mergesort_data)
# edit(mergesort_data)
# class(mergesort_data)
Min1 <- apply(mergesort_data, 1, min)
Max1 <- apply(mergesort_data, 1, max)
Mean1 <- apply(mergesort_data, 1, mean)
x_val <- 150*(1:20)
(Min1/(x_val * log(x_val,base = 2)))
(Mean1/(x_val * log(x_val,base = 2)))
(Max1/(x_val * log(x_val,base = 2)))


par(mfrow = c(1,2))

plot(x_val,Max1,type = "b",col = "red",xlab = "ArrSize",ylab = "Num Of swaps")
points(x_val,Mean1,col = "blue",type = "b")
points(x_val,Min1,col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.8)

plot(x_val,Max1/(x_val * log(x_val,base = 2)),type = "b",ylim = c(0.45,0.8),col = "red",xlab = "ArrSize",ylab = "Num of swaps/(ArrSize)")
points(x_val,Mean1/(x_val * log(x_val,base = 2)),col = "blue",type = "b")
points(x_val,Min1/(x_val * log(x_val,base = 2)),col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.8)

