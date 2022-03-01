.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_4D - Debug ]----------"
	@cd "Lab_4D" && "$(MAKE)" -f  "Lab_4D.mk"
clean:
	@echo "----------Cleaning project:[ Lab_4D - Debug ]----------"
	@cd "Lab_4D" && "$(MAKE)" -f  "Lab_4D.mk" clean
