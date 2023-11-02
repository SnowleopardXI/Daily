library(ggplot2)
p <- seq(0.01, 0.99, by = 0.01)
H <- -p * log2(p) - (1 - p) * log2(1 - p)
data <- data.frame(p, H)
ggplot(data, aes(x = p, y = H)) +
    geom_line(color = "blue") +
    labs(title = "熵 H 作为概率 p 的函数",x = "p",y = "H(X)") +
    theme_minimal()
