.PHONY: clean All

All:
	@echo "----------Building project:[ Lab_6B - Debug ]----------"
	@cd "Lab_6B" && "$(MAKE)" -f  "Lab_6B.mk"
clean:
	@echo "----------Cleaning project:[ Lab_6B - Debug ]----------"
	@cd "Lab_6B" && "$(MAKE)" -f  "Lab_6B.mk" clean
