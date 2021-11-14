(define first car)
(define rest cdr)

(define empty?
    (lambda (L)
        (if L
            nil
            t)))

(define vec '(21848 26492 19808 26960 13869 31133 28097 11570 7897 21912 20773 25164 4049 16050 30307 22080 3125 30276 8031 5911 1622 9537 11342 28923 9452 22083 1761 25164 7864 4894 23788 29712 31387 10828 23904 12488 9194 19233 24059 17091 8377 12064 9487 12426 28114 7027 1738 31240 4535 9769 4383 6158 19307 15725 2313 28759 5040 4075 21155 12904 8969 12175 9848 7588 23003 984 20077 32197 20217 11368 16521 28594 23432 26008 8253 18778 267 9991 17250 4803 19761 21633 10961 6300 4590 13274 2291 9630 17349 23446 22534 26319 2853 32382 1139 25856 598 21216 25286 20815))

(define insert-in-sorted
    (lambda (L i)
        (if (empty? L)
            (cons i nil)
            (if (< i (first L))
                (cons i L)
                (cons (first L) (insert-in-sorted (rest L) i))))))

(define insertion-sort-rec
    (lambda (L Ls)
        (if (empty? L)
            Ls
            (insertion-sort-rec (rest L) (insert-in-sorted Ls (first L))))))

(define insertion-sort
    (lambda (L)
        (insertion-sort-rec L nil)))

(insertion-sort vec)