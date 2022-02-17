.PHONY: clean All

All:
	@echo "----------Building project:[ Lab3DE - Debug ]----------"
	@cd "Lab3DE" && "$(MAKE)" -f  "Lab3DE.mk"
clean:
	@echo "----------Cleaning project:[ Lab3DE - Debug ]----------"
	@cd "Lab3DE" && "$(MAKE)" -f  "Lab3DE.mk" clean
