#lang racket

(define (input-triplet)
  (list (read) (read) (read)))

(define (do-it t1 t2 a b)
  (cond
    [(empty? t1) 
     (printf "~a ~a~n" a b)
     (void)]
    [(> (car t1) (car t2)) (do-it (cdr t1) (cdr t2) (add1 a) b)]
    [(< (car t1) (car t2)) (do-it (cdr t1) (cdr t2) a (add1 b))]
    [(= (car t1) (car t2)) (do-it (cdr t1) (cdr t2) a b)]))

(do-it (input-triplet) (input-triplet) 0 0)
