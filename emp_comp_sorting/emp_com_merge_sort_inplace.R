# for comparison n*log(n,base=2)

inplace_mergesort_comp_data = read.csv(file.choose(),sep = ",",header = F)
inplace_mergesort_comp_data <- as.matrix(inplace_mergesort_comp_data)
# edit(inplace_mergesort_comp_data)
# class(inplace_mergesort_comp_data)
Min_comp <- apply(inplace_mergesort_comp_data, 1, min)
Max_comp <- apply(inplace_mergesort_comp_data, 1, max)
Mean_comp <- apply(inplace_mergesort_comp_data, 1, mean)
x_val <- 200*(1:20)
(Min_comp/(x_val * log(x_val,base = 2)))
(Mean_comp/(x_val * log(x_val,base = 2)))
(Max_comp/(x_val * log(x_val,base = 2)))


par(mfrow = c(1,2))

plot(x_val,Max_comp,type = "b",col = "red",xlab = "ArrSize",ylab = "Num Of comp")
points(x_val,Mean_comp,col = "blue",type = "b")
points(x_val,Min_comp,col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.7)

plot(x_val,Max_comp/(x_val * log(x_val,base = 2)),ylim = c(0.0,1.2),type = "b",col = "red",xlab = "ArrSize",ylab = "Num of swaps/(ArSize*log(ArSize))")
points(x_val,Mean_comp/(x_val * log(x_val,base = 2)),col = "blue",type = "b")
points(x_val,Min_comp/(x_val * log(x_val,base = 2)),col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.7)



# for swap comp n*n*log(n,base=2)

inplace_mergesort_swap_data = read.csv(file.choose(),sep = ",",header = F)
inplace_mergesort_swap_data <- as.matrix(inplace_mergesort_swap_data)
# edit(inplace_mergesort_swap_data)
# class(inplace_mergesort_swap_data)
Min_swap <- apply(inplace_mergesort_swap_data, 1, min)
Max_swap <- apply(inplace_mergesort_swap_data, 1, max)
Mean_swap <- apply(inplace_mergesort_swap_data, 1, mean)
# x_val <- 100*(1:20)
(Min_swap/(x_val * x_val * log(x_val,base = 2)))
(Mean_swap/(x_val * x_val * log(x_val,base = 2)))
(Max_swap/(x_val * x_val * log(x_val,base = 2)))


par(mfrow = c(1,2))

plot(x_val,Max_swap,ylim = c(0,80000),type = "b",col = "red",xlab = "ArrSize",ylab = "Num Of swaps")
points(x_val,Mean_swap,col = "blue",type = "b")
points(x_val,Min_swap,col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.7)

plot(x_val,Max_swap/(x_val * x_val * log(x_val,base = 2)),ylim = c(0.0,0.1),type = "b",col = "red",xlab = "ArrSize",ylab = "Num of swaps/(ArSize*ArSize*log(ArSize))")
points(x_val,Mean_swap/(x_val * x_val * log(x_val,base = 2)),col = "blue",type = "b")
points(x_val,Min_swap/(x_val * x_val * log(x_val,base = 2)),col = "green",type = "b")
legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.7)

# plot(x_val,Max_swap/(x_val * x_val ),type = "b",col = "red",xlab = "ArrSize",ylab = "Num of swaps/(ArSize*ArSize*log(ArSize))")
# points(x_val,Mean_swap/(x_val * x_val ),col = "blue",type = "b")
# points(x_val,Min_swap/(x_val * x_val ),col = "green",type = "b")
# legend("topleft",legend = c("max","mean","min"),col = c("red","blue","green"),lty = 1:3,cex = 0.7)
