;; a simple major mode for minimalType VM code

(setq mtvm-highlights
      '(("push\\|add\\|hlt" . font-lock-function-name-face)
	("#\\|" . font-lock-constant-face)))

(define-derived-mode mtvm-mode fundamental-mode "mtVM"
  "major mode for editing minimalType VM code"
  (setq font-lock-defaults '(mtvm-highlights)))

(provide 'mtvm-mode)
