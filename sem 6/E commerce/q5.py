import hashlib
import time

class PaymentGateway:
    """Simulated Stripe-like payment gateway"""
    
    def __init__(self):
        self.transactions = []
    
    def process_payment(self, amount, card_number, cvv, exp_date):
        # Simulate payment processing
        print("\n Processing payment...")
        time.sleep(1)
        
        # Basic validation
        if len(card_number) != 16 or len(cvv) != 3:
            return {'success': False, 'message': 'Invalid card details'}
        
        # Simulate payment
        transaction_id = hashlib.md5(f"{card_number}{time.time()}".encode()).hexdigest()[:12]
        
        transaction = {
            'id': transaction_id,
            'amount': amount,
            'status': 'completed',
            'timestamp': time.time()
        }
        self.transactions.append(transaction)
        
        return {
            'success': True,
            'transaction_id': transaction_id,
            'amount': amount,
            'message': 'Payment successful'
        }

class EcommerceCheckout:
    def __init__(self):
        self.cart = [
            {'name': 'Laptop', 'price': 999.99},
            {'name': 'Mouse', 'price': 25.50},
            {'name': 'Keyboard', 'price': 75.00}
        ]
        self.gateway = PaymentGateway()
    
    def show_cart(self):
        print("\n" + "="*50)
        print("CHECKOUT")
        print("="*50)
        total = 0
        for item in self.cart:
            print(f"{item['name']} - ${item['price']:.2f}")
            total += item['price']
        print("-"*50)
        print(f"TOTAL: ${total:.2f}")
        print("="*50)
        return total
    
    def checkout(self, card_number, cvv, exp_date):
        total = sum(item['price'] for item in self.cart)
        
        result = self.gateway.process_payment(total, card_number, cvv, exp_date)
        
        if result['success']:
            print(f"\n✓ {result['message']}")
            print(f"Transaction ID: {result['transaction_id']}")
            print(f"Amount Charged: ${result['amount']:.2f}")
            print("Thank you for your purchase!")
        else:
            print(f"\n✗ Payment Failed: {result['message']}")
        
        return result

# Demo
store = EcommerceCheckout()
store.show_cart()

# Process payment
store.checkout(
    card_number='4532014223941477',
    cvv='123',
    exp_date='12/25'
)