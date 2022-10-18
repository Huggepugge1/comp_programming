(defvar a)
(defvar b)
(defvar c)
(defvar p1)
(defvar p2)
(defvar ans)

(setq a (read) b (read))
(setf c (make-array '(1000000)))

(loop for x from 0 to (- b 1)
      do (setf (aref c x) (read))
)

(setq c (sort c #'<))

(setq p1 0 p2 (- 1000000 1) ans 0)

(loop while (< p1 p2)
      do (if (< (* (aref c p1) (aref c p2)) a)
           (setq p1 (+ p1 1))
           (setq p1 (+ p1 1) p2 (- p2 1) ans (+ ans 1))
      )
)

(princ ans)(terpri)
