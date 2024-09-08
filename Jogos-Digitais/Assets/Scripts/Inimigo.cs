using UnityEngine;

public class Inimigo : MonoBehaviour
{
    public int pontos = 200;
    public Movimento movimento { get; private set; }
    public InimigoHome home { get; private set; }
    public InimigoScatter scatter { get; private set; }
    public InimigoChase chase { get; private set; }
    public InimigoAssustado assustado { get; private set; }
    public InimigoComportamento comportamentoInicial;
    public Transform target;

    private void Awake()
    {
        this.movimento = GetComponent<Movimento>();
        this.home = GetComponent<InimigoHome>();
        this.scatter = GetComponent<InimigoScatter>();
        this.chase = GetComponent<InimigoChase>();
        this.assustado = GetComponent<InimigoAssustado>();
    }

    private void Start()
    {
        ResetState();
    }

    public void ResetState()
    {
        this.gameObject.SetActive(true);
        this.movimento.ResetState();

        this.assustado.Disable();
        this.chase.Disable();
        this.scatter.Enable();
        
        if (this.home != this.comportamentoInicial)
        {
            this.home.Disable();
        }
        if (this.comportamentoInicial != null)
        {
            this.comportamentoInicial.Enable();
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.layer == LayerMask.NameToLayer("Muscleman"))
        {
            if (this.assustado.enabled)
            {
                FindObjectOfType<GameManager>().InimigoDerrotado(this);
            }else{
                FindAnyObjectByType<GameManager>().PlayerDerrotado();
            }
        }
    }
}
