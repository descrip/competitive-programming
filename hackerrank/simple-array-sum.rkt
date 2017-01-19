#lang racket

(define (recursive-sum n x)
  (if (equal? n 0) x (recursive-sum (- n 1) (+ x (read)))))

(recursive-sum (read) 0)
